/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 02:24:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_putnull(t_ctx *ctx)
{
	if (ctx->field_width > 6)
	{
		if (!(ctx->flags & (1 << 0))
			&& ft_padding(' ', ctx->field_width - 6) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		write(1, "(null)", 6);
		if (ctx->flags & (1 << 0)
			&& ft_padding(' ', ctx->field_width - 6) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	else
	{
		ctx->field_width = 6;
		write(1, "(null)", 6);
	}
	ctx->len += ctx->field_width;
	return (SUCCESS);
}

static int	ft_padded_putnstr(char *s, t_ctx *ctx)
{
	if (!(ctx->flags & (1 << 0))
		&& ft_padding(' ', ctx->field_width - ctx->precision) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, s, ctx->precision);
	if (ctx->flags & (1 << 0)
		&& ft_padding(' ', ctx->field_width - ctx->precision) == MALLOC_ERRNO)
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
	if (!ctx->precised || ctx->precision > len)
		ctx->precision = len;
	if (ctx->field_width < ctx->precision)
		ctx->field_width = ctx->precision;
	ctx->len += ctx->field_width;
	if (ctx->field_width > ctx->precision)
		return (ft_padded_putnstr(s, ctx));
	write(1, s, ctx->precision);
	return (SUCCESS);
}
