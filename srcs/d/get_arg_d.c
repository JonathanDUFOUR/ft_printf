/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:19:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/03 02:56:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	flag_exception(t_ctx *ctx);
int		padded_putllnbr(LLD n, uint32_t len, t_ctx *ctx);

static LLD	get_right_type(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return ((LLD)va_arg(va, LD));
	else if (ctx->flags & (1 << 6))
		return ((LLD)va_arg(va, LLD));
	else if (ctx->flags & (1 << 7))
		return ((LLD)((HD)va_arg(va, int)));
	else if (ctx->flags & (1 << 8))
		return ((LLD)((HHD)va_arg(va, int)));
	else
		return ((LLD)va_arg(va, int));
}

int	get_arg_d(t_ctx *ctx, va_list va)
{
	LLD			n;
	uint32_t	len;

	n = get_right_type(ctx, va);
	if (!ctx->prec && !n)
	{
		if (ctx->flags & (1 << 2) || ctx->flags & (1 << 3))
			flag_exception(ctx);
		if (padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	len = dlen(n);
	if (ctx->prec < (len - (n < 0)))
		ctx->prec = len - (n < 0);
	if (ctx->fwidth < (ctx->prec + !!((n < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)))))
		ctx->fwidth = ctx->prec + !!((n < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putllnbr(n, len, ctx));
	putllnbr(n);
	return (SUCCESS);
}
