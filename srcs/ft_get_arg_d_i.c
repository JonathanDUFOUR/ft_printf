/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 03:34:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_padded_putnbr(int n, uint32_t intlen, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->fwidth - ctx->prec - (n < 0);
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& ft_padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (n < 0)
		write(1, "-", 1);
	if (ctx->flags & (1 << 1) && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - (intlen - (n < 0));
	if (padlen && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putunbr((n < 0) * (-n) + (n >= 0) * n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - (n < 0);
		if (ft_padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	ft_get_arg_d_i(t_ctx *ctx, va_list va)
{
	int			n;
	uint32_t	intlen;

	n = va_arg(va, uint32_t);
	if (!ctx->prec && !n)
	{
		if (ft_padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	intlen = ft_intlen(n);
	if (ctx->prec < (intlen - (n < 0)))
		ctx->prec = intlen - (n < 0);
	if (ctx->fwidth < (ctx->prec + (n < 0)))
		ctx->fwidth = ctx->prec + (n < 0);
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > intlen)
		return (ft_padded_putnbr(n, intlen, ctx));
	ft_putnbr(n);
	return (SUCCESS);
}
