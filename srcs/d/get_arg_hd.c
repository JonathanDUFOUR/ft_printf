/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_hd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:19:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/02 01:42:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int		padded_putnbr(long long int n, uint32_t len, t_ctx *ctx);
void	putllnbr(long long int n);

static void	flag_exception(t_ctx *ctx)
{
	if (ctx->flags & (1 << 2))
		write(1, "+", 1);
	else if (ctx->flags & (1 << 3))
		write(1, " ", 1);
	if (ctx->fwidth)
		--ctx->fwidth;
	++ctx->len;
}

int	get_arg_hd(t_ctx *ctx, va_list va)
{
	int			n;
	uint32_t	len;

	n = va_arg(va, int);
	if (!ctx->prec && !n)
	{
		if (ctx->flags & (1 << 2) || ctx->flags & (1 << 3))
			flag_exception(ctx);
		if (padding(' ', ctx->fwidth) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	len = dlen((long long int)n);
	if (ctx->prec < (len - (n < 0)))
		ctx->prec = len - (n < 0);
	if (ctx->fwidth < (ctx->prec + !!((n < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)))))
		ctx->fwidth = ctx->prec + !!((n < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putnbr((long long int)n, len, ctx));
	putllnbr((long long int)n);
	return (SUCCESS);
}
