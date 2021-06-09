/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putllunbr_hexa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 02:17:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/03 02:38:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	padded_putllunbr_hexa(LLU n, uint32_t len, t_ctx *ctx, int style)
{
	uint32_t	padlen;

	padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4)) * 2;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 4) && style == LOWER)
		write(1, "0x", 2);
	if (ctx->flags & (1 << 4) && style == UPPER)
		write(1, "0X", 2);
	if (ctx->flags & (1 << 1) && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->prec - len;
	if (padlen && padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	putllunbr_hexa(n, (style == LOWER) * 'a' + (style == UPPER) * 'A');
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4)) * 2;
		if (padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}
