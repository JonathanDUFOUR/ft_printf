/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 13:40:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_padded_putnbr(int n, uint32_t intlen, t_ctx *ctx)
{
	char		*padding;
	uint32_t	padlen;

	if (ctx->precision)
	{
		if (ctx->precision < (intlen - (n < 0)))
			ctx->precision = intlen - (n < 0);
		if (!(ctx->flags & (1 << 0)))
		{
			padlen = ctx->field_width - ctx->precision - (n < 0);
			padding = ft_get_padding(' ', padlen);
			if (!padding)
				return (MALLOC_ERRNO);
			write(1, padding, padlen);
			free(padding);
		}
		padlen = (intlen - (n < 0)) - ctx->precision;
		if (padlen)
		{
			padding = ft_get_padding('0', padlen);
			if (!padding)
				return (MALLOC_ERRNO);
			write(1, padding, padlen);
			free(padding);
		}
		ft_putnbr(n);
		if (ctx->flags & (1 << 0))
		{
			padlen = ctx->field_width - ctx->precision - (n < 0);
			padding = ft_get_padding(' ', padlen);
			if (!padding)
				return (MALLOC_ERRNO);
			write(1, padding, padlen);
			free(padding);
		}
	}
	else
	{
		ft_putnbr(n);
	}
	return (SUCCESS);
}

int	ft_get_arg_d_i(t_ctx *ctx, va_list va)
{
	int			n;
	uint32_t	intlen;

	n = va_arg(va, uint32_t);
	intlen = ft_intlen(n);
	if (!ctx->field_width)
		ctx->field_width = intlen;
	ctx->len += ctx->field_width;
	if (ctx->field_width > intlen)
		return (ft_padded_putnbr(n, intlen, ctx));
	ft_putnbr(n);
	return (SUCCESS);
}
