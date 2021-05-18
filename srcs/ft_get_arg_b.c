/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:54:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 03:34:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static void	ft_putnbr_bin(uint32_t n)
{
	char	d;

	if (n > 1)
		ft_putnbr_bin(n / 2);
	d = n % 2 + '0';
	write(1, &d, 1);
}

static int	ft_padded_putnbr_bin(uint32_t n, uint32_t blen, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->fwidth - ctx->prec;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& ft_padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 1) && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - blen;
	if (padlen && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putnbr_bin(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec;
		if (ft_padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	ft_get_arg_b(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	uint32_t	blen;

	n = va_arg(va, uint32_t);
	if (!ctx->prec && !n)
	{
		if (ft_padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	blen = ft_blen(n);
	if (ctx->prec < blen)
		ctx->prec = blen;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > blen)
		return (ft_padded_putnbr_bin(n, blen, ctx));
	ft_putnbr_bin(n);
	return (SUCCESS);
}
