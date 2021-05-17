/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/17 15:31:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_putnil(t_ctx *ctx)
{
	if (ctx->field_width > 5)
	{
		if (!(ctx->flags & (1 << 0))
			&& ft_padding(' ', ctx->field_width - 5) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
		write(1, "(nil)", 5);
		if (ctx->flags & (1 << 0)
			&& ft_padding(' ', ctx->field_width - 5) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	else
	{
		ctx->field_width = 5;
		write(1, "(nil)", 5);
	}
	ctx->len += ctx->field_width;
	return (SUCCESS);
}

static void	ft_putnbr_hexa(uint64_t n)
{
	uint32_t	mod;
	char		d;

	if (n > 15)
		ft_putnbr_hexa(n / 16);
	mod = n % 16;
	if (mod < 10)
		d = mod + '0';
	else
		d = mod - 10 + 'a';
	write(1, &d, 1);
}

static int	ft_padded_putnbr_hexa(uint64_t n, uint32_t plen, t_ctx *ctx)
{
	uint32_t	padlen;

	padlen = ctx->field_width - ctx->precision - 2;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& ft_padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, "0x", 2);
	if (ctx->flags & (1 << 1) && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	padlen = ctx->precision - plen;
	if (padlen && ft_padding('0', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putnbr_hexa(n);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->field_width - ctx->precision - 2;
		if (ft_padding(' ', padlen) == MALLOC_ERRNO)
			return (MALLOC_ERRNO);
	}
	return (SUCCESS);
}

int	ft_get_arg_p(t_ctx *ctx, va_list va)
{
	uint64_t	n;
	uint32_t	plen;

	n = va_arg(va, uint64_t);
	if (!n)
		return (ft_putnil(ctx));
	plen = ft_plen(n);
	if (ctx->precision < plen)
		ctx->precision = plen;
	if (ctx->field_width < (ctx->precision + 2))
		ctx->field_width = ctx->precision + 2;
	ctx->len += ctx->field_width;
	if (ctx->field_width > (plen + 2))
		return (ft_padded_putnbr_hexa(n, plen, ctx));
	write(1, "0x", 2);
	ft_putnbr_hexa(n);
	return (SUCCESS);
}
