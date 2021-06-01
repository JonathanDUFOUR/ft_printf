/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:45:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/02 01:38:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	putllunbr(unsigned long long int n)
{
	char	d;

	if (n > 9)
		putllunbr(n / 10);
	d = n % 10 + '0';
	write(1, &d, 1);
}

static uint32_t	field_width_padlen(long long int n, t_ctx *ctx)
{
	return (ctx->fwidth
		- ctx->prec
		- !!((n < 0) || (ctx->flags & (1 << 2)) || (ctx->flags & (1 << 3))));
}

int	padded_putnbr(long long int n, uint32_t len, t_ctx *ctx)
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
