/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_d_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:19:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/19 00:45:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	padded_putnbr(int n, uint32_t len, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->fwidth - ctx->prec - ((n < 0) || !!(ctx->flags & (1 << 2)) || !!(ctx->flags & (1 << 3)));
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (n < 0)
		write(1, "-", 1);
	else if (ctx->flags & (1 << 2))
		write(1, "+", 1);
	else if (ctx->flags & (1 << 3))
		write(1, " ", 1);
	if (ctx->flags & (1 << 1) && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - (len - ((n < 0) || !!(ctx->flags & (1 << 2)) || !!(ctx->flags & (1 << 3))));
	if (padlen && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putunbr((n < 0) * (-n) + (n >= 0) * n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - (n < 0);
		if (padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	get_arg_d_lower(t_ctx *ctx, va_list va)
{
	int			n;
	uint32_t	len;

	n = va_arg(va, uint32_t);
	if (!ctx->prec && !n)
	{
		if (padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	len = ft_intlen(n);
	if (ctx->prec < (len - (n < 0)))
		ctx->prec = len - (n < 0);
	if (ctx->fwidth < (ctx->prec + ((n < 0) || !!(ctx->flags & (1 << 2)) || !!(ctx->flags & (1 << 3)))))
		ctx->fwidth = ctx->prec + ((n < 0) || !!(ctx->flags & (1 << 2)) || !!(ctx->flags & (1 << 3)));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putnbr(n, len, ctx));
	ft_putnbr(n);
	return (SUCCESS);
}
