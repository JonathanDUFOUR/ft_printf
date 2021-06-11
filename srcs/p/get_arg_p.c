/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/07 11:47:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	padded_putaddr(LU n, uint32_t len, t_ctx *ctx);

int	get_arg_p(t_ctx *ctx, va_list va)
{
	LU			n;
	uint32_t	len;

	n = va_arg(va, LU);
	if (!ctx->prec && !n)
	{
		if (ctx->fwidth < 2)
			ctx->fwidth = 2;
		if (padding(' ', ctx->fwidth - 2) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		write(1, "0x", 2);
		return (SUCCESS);
	}
	len = plen(n);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + 2))
		ctx->fwidth = ctx->prec + 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > (len + 2))
		return (padded_putaddr(n, len, ctx));
	write(1, "0x", 2);
	putllunbr_hexa(n, 'a');
	return (SUCCESS);
}
