/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/11 11:20:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "internal.h"
#include "enum/e_ret.h"

int	padded_putnstr(
	char const *str,
	t_ctx *const ctx)
{
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', ctx->fwidth - ctx->prec))
		return (MALLOC_ERR);
	if (ctx->flags & (1 << 1)
		&& padding('0', ctx->fwidth - ctx->prec))
		return (MALLOC_ERR);
	write(1, str, ctx->prec);
	if (ctx->flags & (1 << 0)
		&& padding(' ', ctx->fwidth - ctx->prec))
		return (MALLOC_ERR);
	return (SUCCESS);
}

int	padded_putnwstr(
	wchar_t const *str,
	t_ctx *const ctx,
	int len,
	int const size)
{
	len = ctx->prec;
	if (!(ctx->flags & (1 << 0))
		&& padding(' ', ctx->fwidth - size))
		return (MALLOC_ERR);
	while (len--)
		if (ft_putchar(*str++) == -1)
			return (WRITE_ERR);
	if (ctx->flags & (1 << 0)
		&& padding(' ', ctx->fwidth - size))
		return (MALLOC_ERR);
	return (SUCCESS);
}

static int	get_char_ptr(t_ctx *const ctx, va_list va)
{
	char const	*str = va_arg(va, char *);
	int			len;

	if (!str)
		return (putnull(ctx));
	len = ft_strlen(str);
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > ctx->prec)
		return (padded_putnstr(str, ctx));
	write(1, str, ctx->prec);
	return (SUCCESS);
}

static int	get_wchar_ptr(t_ctx *const ctx, va_list va)
{
	wchar_t const	*str = va_arg(va, wchar_t *);
	int				len;
	int				size;

	if (!str)
		return (putnull(ctx));
	len = ft_wstrlen(str);
	size = ft_wstrsize(str);
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += size;
	if (size < ctx->fwidth)
		ctx->len += ctx->fwidth;
	if (ctx->fwidth > size)
		return (padded_putnwstr(str, ctx, len, size));
	while (ctx->prec--)
		ft_putchar(*str++);
	return (SUCCESS);
}

int	cvrt_s(t_ctx *const ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return (get_wchar_ptr(ctx, va));
	else
		return (get_char_ptr(ctx, va));
}
