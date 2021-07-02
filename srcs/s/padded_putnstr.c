/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:01:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/02 14:49:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "e_ret.h"

int	padded_putnstr(char *s, t_ctx *ctx)
{
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', ctx->fwidth - ctx->prec) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 1)
		&& padding('0', ctx->fwidth - ctx->prec) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, s, ctx->prec);
	if (ctx->flags & (1 << 0)
		&& padding(' ', ctx->fwidth - ctx->prec) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}
