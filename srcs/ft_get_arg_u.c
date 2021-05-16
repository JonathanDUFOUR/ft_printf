/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 18:18:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_padded_putunbr(uint32_t n, uint32_t uintlen, t_ctx *ctx)
{
	char		*padding;
	uint32_t	padlen;

	padlen = ctx->field_width - ctx->precision;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1)))
	{
		padding = ft_get_padding(' ', padlen);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, padlen);
		free(padding);
	}
	if (ctx->flags & (1 << 1))
	{
		padding = ft_get_padding('0', padlen);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, padlen);
		free(padding);
	}
	padlen = ctx->precision - uintlen;
	if (padlen)
	{
		padding = ft_get_padding('0', padlen);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, padlen);
		free(padding);
	}
	ft_putunbr(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->field_width - ctx->precision;
		padding = ft_get_padding(' ', padlen);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, padlen);
		free(padding);
	}
	return (SUCCESS);
}

int	ft_get_arg_u(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	uint32_t	uintlen;
	char		*padding;

	n = va_arg(va, uint32_t);
	if (!ctx->precision && !n)
	{
		padding = ft_get_padding(' ', ctx->field_width);
		if (!padding)
			return (MALLOC_ERRNO);
		write(1, padding, ctx->field_width);
		free(padding);
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
