/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 03:34:44 by jodufour         ###   ########.fr       */
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

	padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4)) * 2;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& ft_padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 4))
		write(1, "0x", 2);
	if (ctx->flags & (1 << 1) && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - xlen;
	if (padlen && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putnbr_hexa(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec;
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
	if (!ctx->prec && !n)
	{
		if (ft_padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	if (!n)
		ctx->flags &= ~(1 << 4);
	xlen = ft_xlen(n);
	if (ctx->prec < xlen)
		ctx->prec = xlen;
	if (ctx->fwidth < (ctx->prec + 2 * !!(ctx->flags & (1 << 4))))
		ctx->fwidth = ctx->prec + 2 * !!(ctx->flags & (1 << 4));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > xlen)
		return (ft_padded_putnbr_hexa(n, xlen, ctx));
	ft_putnbr_hexa(n);
	return (SUCCESS);
}
