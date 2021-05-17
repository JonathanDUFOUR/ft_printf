/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:35:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/17 21:08:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static void	ft_putnbr_oct(uint32_t n)
{
	char	d;

	if (n > 7)
		ft_putnbr_oct(n / 8);
	d = n % 8 + '0';
	write(1, &d, 1);
}

static int	ft_padded_putnbr_oct(uint32_t n, uint32_t olen, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->field_width - ctx->precision;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& ft_padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	if (ctx->flags & (1 << 1) && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->precision - olen;
	if (padlen && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putnbr_oct(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->field_width - ctx->precision;
		if (ft_padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	ft_get_arg_o(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	uint32_t	olen;

	n = va_arg(va, uint32_t);
	if (!ctx->precision && !n)
	{
		if (ft_padding(' ', ctx->field_width) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		ctx->len += ctx->field_width;
		return (SUCCESS);
	}
	olen = ft_olen(n);
	if (ctx->precision < olen)
		ctx->precision = olen;
	if (ctx->field_width < ctx->precision)
		ctx->field_width = ctx->precision;
	ctx->len += ctx->field_width;
	if (ctx->field_width > olen)
		return (ft_padded_putnbr_oct(n, olen, ctx));
	ft_putnbr_oct(n);
	return (SUCCESS);
}
