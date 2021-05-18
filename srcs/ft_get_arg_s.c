/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 03:34:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_putnull(t_ctx *ctx)
{
	if (ctx->fwidth > 6)
	{
		if (!(ctx->flags & (1 << 0))
			&& ft_padding(' ', ctx->fwidth - 6) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		write(1, "(null)", 6);
		if (ctx->flags & (1 << 0)
			&& ft_padding(' ', ctx->fwidth - 6) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	else
	{
		ctx->fwidth = 6;
		write(1, "(null)", 6);
	}
	ctx->len += ctx->fwidth;
	return (SUCCESS);
}

static int	ft_padded_putnstr(char *s, t_ctx *ctx)
{
	if (!(ctx->flags & (1 << 0))
		&& ft_padding(' ', ctx->fwidth - ctx->prec) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, s, ctx->prec);
	if (ctx->flags & (1 << 0)
		&& ft_padding(' ', ctx->fwidth - ctx->prec) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}

int	ft_get_arg_s(t_ctx *ctx, va_list va)
{
	char		*s;
	uint32_t	len;

	s = va_arg(va, char *);
	if (!s)
		return (ft_putnull(ctx));
	len = (uint32_t)ft_strlen(s);
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > ctx->prec)
		return (ft_padded_putnstr(s, ctx));
	write(1, s, ctx->prec);
	return (SUCCESS);
}
