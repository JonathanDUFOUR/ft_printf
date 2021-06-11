/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/06 17:01:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

uint32_t	wstrlen(wchar_t *s);
uint32_t	wstrsize(wchar_t *s);
int			putnull(t_ctx *ctx);
int			padded_putnstr(char *s, t_ctx *ctx);
int			padded_putnwstr(wchar_t *s, t_ctx *ctx, uint32_t len,
				uint32_t size);

static int	get_char_ptr(t_ctx *ctx, va_list va)
{
	char		*s;
	uint32_t	len;

	s = va_arg(va, char *);
	if (!s)
		return (putnull(ctx));
	len = (uint32_t)ft_strlen(s);
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > ctx->prec)
		return (padded_putnstr(s, ctx));
	write(1, s, ctx->prec);
	return (SUCCESS);
}

static int	get_wchar_ptr(t_ctx *ctx, va_list va)
{
	wchar_t		*s;
	uint32_t	len;
	uint32_t	size;

	s = va_arg(va, wchar_t *);
	if (!s)
		return (putnull(ctx));
	len = wstrlen(s);
	size = wstrsize(s);
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += size;
	if (size < ctx->fwidth)
		ctx->len += ctx->fwidth;
	if (ctx->fwidth > size)
		return (padded_putnwstr(s, ctx, len, size));
	while (ctx->prec--)
		ft_putchar(*s++);
	return (SUCCESS);
}

int	get_arg_s(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return (get_wchar_ptr(ctx, va));
	else
		return (get_char_ptr(ctx, va));
}
