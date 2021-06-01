/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_o_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:35:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/20 20:42:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	padded_putnbr_oct(uint32_t n, uint32_t len, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4));
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 4))
		write(1, "0", 1);
	if (ctx->flags & (1 << 1) && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - len;
	if (padlen && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putnbr_oct(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4));
		if (padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	get_arg_o_lower(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	uint32_t	len;

	n = va_arg(va, uint32_t);
	if (!ctx->prec && !n)
	{
		if (padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	if (!n)
		ctx->flags &= ~(1 << 4);
	len = olen(n);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + !!(ctx->flags & (1 << 4))))
		ctx->fwidth = ctx->prec + !!(ctx->flags & (1 << 4));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putnbr_oct(n, len, ctx));
	ft_putnbr_oct(n);
	return (SUCCESS);
}
