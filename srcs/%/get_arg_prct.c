/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_prct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:58:39 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/02 14:46:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "e_ret.h"

static int	padded_putprct(uint8_t flags, uint32_t padlen)
{
	if (!(flags & (1 << 0)) && !(flags & (1 << 1))
		&& padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (flags & (1 << 1) && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, "%", 1);
	if (flags & (1 << 0) && padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}

int	get_arg_prct(t_ctx *ctx)
{
	if (!ctx->fwidth)
		ctx->fwidth = 1;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		return (padded_putprct(ctx->flags, ctx->fwidth - 1));
	write(1, "%", 1);
	return (SUCCESS);
}
