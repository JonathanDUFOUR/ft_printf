/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/14 05:57:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static char	*ft_padded_itoa(int n, int c, int padlen)
{
	uint32_t	abs;
	char		*output;
	char		*p;
	int			len;

	len = ft_intlen(n) + padlen;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output + len;
	*p-- = 0;
	abs = n;
	if (n >> 31 && --len)
	{
		*output = '-';
		abs = -n;
	}
	while (abs && --len)
	{
		*p-- = (abs % 10) + '0';
		abs /= 10;
	}
	while (len--)
		*p-- = c;
	return (output);
}

static char	*ft_right_padding(char *output, char *dent, int field_width)
{
	int		padlen;
	char	*padding;
	char	*p;

	padlen = field_width - (int)ft_strlen(dent);
	if (padlen > 0)
	{
		padding = malloc((padlen + 1) * sizeof(char));
		if (!padding)
		{
			free(output);
			return (NULL);
		}
		p = padding;
		while (padlen--)
			*p++ = ' ';
		*p = 0;
		p = output;
		output = ft_strjoin(output, padding);
		free(p);
		free(padding);
	}
	return (output);
}

char	*ft_get_arg_d_i(t_ctx *ctx, va_list va)
{
	int		n;
	int		digits;
	char	*output;
	char	*dent;

	n = va_arg(va, int);
	digits = ft_count_digits(n);
	if (ctx->precision > digits)
		dent = ft_padded_itoa(n, '0', ctx->precision - digits);
	else if ((ctx->flags & (1 << 1)) && !(ctx->flags & (1 << 0))
		&& ctx->field_width > (digits + (n < 0)))
		dent = ft_padded_itoa(n, '0', ctx->field_width - digits - (n < 0));
	else
		dent = ft_itoa(n);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	if (ctx->flags & (1 << 0))
		output = ft_right_padding(output, dent, ctx->field_width);
	free(dent);
	return (output);
}
