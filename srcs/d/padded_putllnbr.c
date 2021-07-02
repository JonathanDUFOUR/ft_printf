/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putllnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:45:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/02 14:47:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "e_ret.h"

static uint32_t	field_width_padlen(LLD n, t_ctx *ctx)
{
	return (ctx->fwidth
		- ctx->prec
		- !!((n < 0) || (ctx->flags & (1 << 2)) || (ctx->flags & (1 << 3))));
}

int	padded_putllnbr(LLD n, uint32_t len, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = field_width_padlen(n, ctx);
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
	padlen = ctx->prec - (len - (n < 0));
	if (padlen && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	putllunbr((n < 0) * (-n) + (n >= 0) * n);
	if (ctx->flags & (1 << 0))
	{
		padlen = field_width_padlen(n, ctx);
		if (padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}
