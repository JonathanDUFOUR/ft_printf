/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/14 15:23:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static char	*ft_padded_utoa(uint32_t n, int c, uint32_t padlen)
{
	uint32_t	len;
	char		*output;
	char		*p;

	len = ft_uintlen(n) + padlen;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output + len;
	*p-- = 0;
	while (n && --len)
	{
		*p-- = (n % 10) + '0';
		n /= 10;
	}
	while (len--)
		*p-- = c;
	return (output);
}

char	*ft_get_arg_u(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	int			digits;
	char		*output;
	char		*dent;

	n = va_arg(va, uint32_t);
	digits = (int)ft_uintlen(n);
	if (ctx->precision > digits)
		dent = ft_padded_utoa(n, '0', ctx->precision - digits);
	else if ((ctx->flags & (1 << 1)) && !(ctx->flags & (1 << 0))
		&& ctx->field_width > digits)
		dent = ft_padded_utoa(n, '0', ctx->field_width - digits);
	else
		dent = ft_utoa(n);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	if (output && (ctx->flags & (1 << 0)))
		output = ft_right_padding(output, dent, ' ', ctx->field_width);
	free(dent);
	return (output);
}
