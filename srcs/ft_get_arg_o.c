/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:35:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 03:34:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static void	ft_putnbr_oct(uint32_t n)
{
	char	d;

	if (n > 7)
		ft_putnbr_oct(n / 8);
	d = n % 8 + '0';
	write(1, &d, 1);
}

static int	ft_padded_putnbr_oct(uint32_t n, uint32_t olen, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->fwidth - ctx->prec;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& ft_padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 1) && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - olen;
	if (padlen && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putnbr_oct(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec;
		if (ft_padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	ft_get_arg_o(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	uint32_t	olen;

	n = va_arg(va, uint32_t);
	if (!ctx->prec && !n)
	{
		if (ft_padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	olen = ft_olen(n);
	if (ctx->prec < olen)
		ctx->prec = olen;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > olen)
		return (ft_padded_putnbr_oct(n, olen, ctx));
	ft_putnbr_oct(n);
	return (SUCCESS);
}
