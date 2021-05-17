/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/17 14:45:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static void	ft_putnbr_hexa(uint32_t n)
{
	uint32_t	mod;
	char		d;

	if (n > 15)
		ft_putnbr_hexa(n / 16);
	mod = n % 16;
	if (mod < 10)
		d = mod + '0';
	else
		d = mod - 10 + 'a';
	write(1, &d, 1);
}

static int	ft_padded_putnbr_hexa(uint32_t n, uint32_t xlen, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->field_width - ctx->precision;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& ft_padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 1) && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->precision - xlen;
	if (padlen && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putnbr_hexa(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->field_width - ctx->precision;
		if (ft_padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	ft_get_arg_x(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	uint32_t	xlen;

	n = va_arg(va, uint32_t);
	if (!ctx->precision && !n)
	{
		if (ft_padding(' ', ctx->field_width) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->field_width;
		return (SUCCESS);
	}
	xlen = ft_xlen(n);
	if (ctx->precision < xlen)
		ctx->precision = xlen;
	if (ctx->field_width < ctx->precision)
		ctx->field_width = ctx->precision;
	ctx->len += ctx->field_width;
	if (ctx->field_width > xlen)
		return (ft_padded_putnbr_hexa(n, xlen, ctx));
	ft_putnbr_hexa(n);
	return (SUCCESS);
}
