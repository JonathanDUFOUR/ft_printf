/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/03 03:00:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static LLU	get_right_type(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return ((LLU)va_arg(va, LU));
	else if (ctx->flags & (1 << 6))
		return ((LLU)va_arg(va, LLU));
	else if (ctx->flags & (1 << 7))
		return ((LLU)((HU)va_arg(va, unsigned int)));
	else if (ctx->flags & (1 << 8))
		return ((LLU)((HHU)va_arg(va, unsigned int)));
	else
		return ((LLU)va_arg(va, unsigned int));
}

static int	padded_putunbr(LLU n, uint32_t len, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->fwidth - ctx->prec;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 1) && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - len;
	if (padlen && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	putllunbr(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec;
		if (padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	get_arg_u(t_ctx *ctx, va_list va)
{
	LLU			n;
	uint32_t	len;

	n = get_right_type(ctx, va);
	if (!ctx->prec && !n)
	{
		if (padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	len = ulen((LLU)n);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putunbr(n, len, ctx));
	putllunbr(n);
	return (SUCCESS);
}
