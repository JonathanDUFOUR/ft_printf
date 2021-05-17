/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/17 14:45:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_padded_putunbr(uint32_t n, uint32_t uintlen, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->field_width - ctx->precision;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& ft_padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 1) && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->precision - uintlen;
	if (padlen && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putunbr(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->field_width - ctx->precision;
		if (ft_padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	ft_get_arg_u(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	uint32_t	uintlen;

	n = va_arg(va, uint32_t);
	if (!ctx->precision && !n)
	{
		if (ft_padding(' ', ctx->field_width) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->field_width;
		return (SUCCESS);
	}
	uintlen = ft_uintlen(n);
	if (ctx->precision < uintlen)
		ctx->precision = uintlen;
	if (ctx->field_width < ctx->precision)
		ctx->field_width = ctx->precision;
	ctx->len += ctx->field_width;
	if (ctx->field_width > uintlen)
		return (ft_padded_putunbr(n, uintlen, ctx));
	ft_putunbr(n);
	return (SUCCESS);
}
