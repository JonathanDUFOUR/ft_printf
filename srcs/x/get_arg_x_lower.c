/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_x_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:17:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padded_putllunbr_hexa(LLU n, uint32_t len, t_ctx *ctx, int style);

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

int	get_arg_x_lower(t_ctx *ctx, va_list va)
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
	len = xlen(n);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + !!(ctx->flags & (1 << 4)) * 2))
		ctx->fwidth = ctx->prec + !!(ctx->flags & (1 << 4)) * 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putllunbr_hexa(n, len, ctx, LOWER));
	putllunbr_hexa(n, 'a');
	return (SUCCESS);
}
