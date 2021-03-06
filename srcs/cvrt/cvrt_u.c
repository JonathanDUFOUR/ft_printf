/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:20:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "internal.h"
#include "e_ret.h"

static t_lluint	get_right_type(t_ctx *const ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return ((t_lluint)va_arg(va, t_luint));
	else if (ctx->flags & (1 << 6))
		return ((t_lluint)va_arg(va, t_lluint));
	else if (ctx->flags & (1 << 7))
		return ((t_lluint)((t_huint)va_arg(va, t_uint)));
	else if (ctx->flags & (1 << 8))
		return ((t_lluint)((t_hhuint)va_arg(va, t_uint)));
	else
		return ((t_lluint)va_arg(va, t_uint));
}

static int	padded_putlluint(
	t_lluint const nb,
	int const len,
	t_ctx *const ctx)
{
	int	padlen;

	padlen = ctx->fwidth - ctx->prec;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen))
		return (MALLOC_ERR);
	if (ctx->flags & (1 << 1) && padding('0', padlen))
		return (MALLOC_ERR);
	padlen = ctx->prec - len;
	if (padlen && padding('0', padlen))
		return (MALLOC_ERR);
	ft_putlluint(nb);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec;
		if (padding(' ', padlen))
			return (MALLOC_ERR);
	}
	return (SUCCESS);
}

int	cvrt_u(t_ctx *const ctx, va_list va)
{
	t_lluint const	nb = get_right_type(ctx, va);
	int				len;

	if (!ctx->prec && !nb)
	{
		if (padding(' ', ctx->fwidth))
			return (MALLOC_ERR);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	len = ft_lluintlen(nb);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putlluint(nb, len, ctx));
	ft_putlluint(nb);
	return (SUCCESS);
}
