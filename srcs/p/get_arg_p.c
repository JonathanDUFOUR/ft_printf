/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/02 00:59:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	putnil(t_ctx *ctx)
{
	if (ctx->fwidth > 5)
	{
		if (!(ctx->flags & (1 << 0))
			&& padding(' ', ctx->fwidth - 5) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		write(1, "(nil)", 5);
		if (ctx->flags & (1 << 0)
			&& padding(' ', ctx->fwidth - 5) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	else
	{
		ctx->fwidth = 5;
		write(1, "(nil)", 5);
	}
	ctx->len += ctx->fwidth;
	return (SUCCESS);
}

static void	putnbr_hexa(uint64_t n)
{
	uint32_t	mod;
	char		d;

	if (n > 15)
		putnbr_hexa(n / 16);
	mod = n % 16;
	if (mod < 10)
		d = mod + '0';
	else
		d = mod - 10 + 'a';
	write(1, &d, 1);
}

static int	padded_putnbr_hexa(uint64_t n, uint32_t len, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->fwidth - ctx->prec - 2;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, "0x", 2);
	if (ctx->flags & (1 << 1) && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - len;
	if (padlen && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	putnbr_hexa(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - 2;
		if (padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	get_arg_p(t_ctx *ctx, va_list va)
{
	uint64_t	n;
	uint32_t	len;

	n = va_arg(va, uint64_t);
	if (!n)
		return (putnil(ctx));
	len = plen(n);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + 2))
		ctx->fwidth = ctx->prec + 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > (len + 2))
		return (padded_putnbr_hexa(n, len, ctx));
	write(1, "0x", 2);
	putnbr_hexa(n);
	return (SUCCESS);
}
