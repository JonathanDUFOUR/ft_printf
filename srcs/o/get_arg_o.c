/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:35:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/02 14:48:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "e_ret.h"

int	padded_putllunbr_oct(LLU n, uint32_t len, t_ctx *ctx);

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

int	get_arg_o(t_ctx *ctx, va_list va)
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
	if (!n)
		ctx->flags &= ~(1 << 4);
	len = olen(n);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + !!(ctx->flags & (1 << 4))))
		ctx->fwidth = ctx->prec + !!(ctx->flags & (1 << 4));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putllunbr_oct(n, len, ctx));
	putllunbr_oct(n);
	return (SUCCESS);
}
