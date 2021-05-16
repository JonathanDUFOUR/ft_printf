/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 07:14:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static uint32_t	ft_get_padlen(uint32_t field_width, uint32_t intlen)
{
	if (field_width > intlen)
		return (field_width - intlen);
	return (0);
}

static char	*ft_add_padding(char *output, uint32_t padlen, int c, int n)
{
	if (c == ' ' && n < 0)
		*output-- = '-';
	while (padlen--)
		*output-- = c;
	if (c == '0' && n < 0)
		*output-- = '-';
	return (output);
}

static char	*ft_fill_output(char *output, int n, uint32_t precision)
{
	uint32_t	abs;

	abs = n * (n >= 0) - n * (n < 0);
	while (precision--)
	{
		*output-- = abs % 10 + '0';
		abs /= 10;
	}
	return (output);
}

static char	*ft_padded_itoa(int n, uint32_t intlen, t_ctx *ctx)
{
	char		*output;
	uint32_t	len;

	len = (intlen > ctx->field_width) * intlen
		+ (ctx->field_width >= intlen) * ctx->field_width;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output += len;
	*output-- = 0;
	ctx->field_width = ft_get_padlen(ctx->field_width, intlen);
	if (ctx->flags & (1 << 0))
		output = ft_add_padding(output, ctx->field_width, ' ', 0);
	output = ft_fill_output(output, n, ctx->precision);
	if (!(ctx->flags & (1 << 0)))
	{
		if (ctx->flags & (1 << 1))
			output = ft_add_padding(output, ctx->field_width, '0', n);
		else
			output = ft_add_padding(output, ctx->field_width, ' ', n);
	}
	else if (n < 0)
		*output-- = '-';
	return (++output);
}

char	*ft_get_arg_d_i(t_ctx *ctx, va_list va)
{
	int			n;
	uint32_t	digits;
	char		*output;
	char		*dent;

	n = va_arg(va, uint32_t);
	digits = ft_intlen(n) - (n < 0);
	if (digits > ctx->precision)
		ctx->precision = digits;
	dent = ft_padded_itoa(n, ctx->precision + (n < 0), ctx);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	free(dent);
	return (output);
}
