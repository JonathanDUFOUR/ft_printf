/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putllunbr_oct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 02:06:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/03 02:33:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	padded_putllunbr_oct(LLU n, uint32_t len, t_ctx *ctx)
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
	putllunbr_oct(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4));
		if (padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}
