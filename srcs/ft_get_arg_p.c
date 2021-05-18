/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 03:34:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_putnil(t_ctx *ctx)
{
	if (ctx->fwidth > 5)
	{
		if (!(ctx->flags & (1 << 0))
			&& ft_padding(' ', ctx->fwidth - 5) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		write(1, "(nil)", 5);
		if (ctx->flags & (1 << 0)
			&& ft_padding(' ', ctx->fwidth - 5) == MALLOC_ERRNO)
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

static void	ft_putnbr_hexa(uint64_t n)
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

static int	ft_padded_putnbr_hexa(uint64_t n, uint32_t plen, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->fwidth - ctx->prec - 2;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& ft_padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, "0x", 2);
	if (ctx->flags & (1 << 1) && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - plen;
	if (padlen && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putnbr_hexa(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - 2;
		if (ft_padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	ft_get_arg_p(t_ctx *ctx, va_list va)
{
	uint64_t	n;
	uint32_t	plen;

	n = va_arg(va, uint64_t);
	if (!n)
		return (ft_putnil(ctx));
	plen = ft_plen(n);
	if (ctx->prec < plen)
		ctx->prec = plen;
	if (ctx->fwidth < (ctx->prec + 2))
		ctx->fwidth = ctx->prec + 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > (plen + 2))
		return (ft_padded_putnbr_hexa(n, plen, ctx));
	write(1, "0x", 2);
	ft_putnbr_hexa(n);
	return (SUCCESS);
}
