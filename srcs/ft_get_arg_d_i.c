/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 17:26:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_padded_putnbr(int n, uint32_t intlen, t_ctx *ctx)
{
	char		*padding;
	uint32_t	padlen;

	padlen = ctx->field_width - ctx->precision - (n < 0);
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1)))
	{
		padding = ft_get_padding(' ', padlen);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, padlen);
		free(padding);
	}
	if (n < 0)
		write(1, "-", 1);
	if (ctx->flags & (1 << 1))
	{
		padding = ft_get_padding('0', padlen);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, padlen);
		free(padding);
	}
	padlen = ctx->precision - (intlen - (n < 0));
	if (padlen)
	{
		padding = ft_get_padding('0', padlen);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, padlen);
		free(padding);
	}
	ft_putunbr(FT_ABS(n));
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->field_width - ctx->precision - (n < 0);
		padding = ft_get_padding(' ', padlen);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, padlen);
		free(padding);
	}
	return (SUCCESS);
}

int	ft_get_arg_d_i(t_ctx *ctx, va_list va)
{
	int			n;
	uint32_t	intlen;
	char		*padding;

	n = va_arg(va, uint32_t);
	if (!ctx->precision && !n)
	{
		padding = ft_get_padding(' ', ctx->field_width);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, ctx->field_width);
		free(padding);
		ctx->len += ctx->field_width;
		return (SUCCESS);
	}
	intlen = ft_intlen(n);
	if (ctx->precision < (intlen - (n < 0)))
		ctx->precision = intlen - (n < 0);
	if (ctx->field_width < (ctx->precision + (n < 0)))
		ctx->field_width = ctx->precision + (n < 0);
	ctx->len += ctx->field_width;
	if (ctx->field_width > intlen)
		return (ft_padded_putnbr(n, intlen, ctx));
	ft_putnbr(n);
	return (SUCCESS);
}
