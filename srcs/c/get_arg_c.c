/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:29:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/05 15:00:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

uint32_t	wclen(wchar_t c);

static int	padded_putchar(char c, uint8_t flags, uint32_t padlen)
{
	if (!(flags & (1 << 0)) && padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, &c, 1);
	if (flags & (1 << 0) && padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}

static int	get_char(t_ctx *ctx, va_list va)
{
	char	c;

	c = (char)va_arg(va, int);
	if (!ctx->fwidth)
		ctx->fwidth = 1;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		return (padded_putchar(c, ctx->flags, ctx->fwidth - 1));
	write(1, &c, 1);
	return (SUCCESS);
}

static int	padded_putunicode(wchar_t c, uint8_t flags, uint32_t padlen)
{
	if (!(flags & (1 << 0)) && padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	ft_putchar(c);
	if (flags & (1 << 0) && padding(' ', padlen) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}

static int	get_unicode(t_ctx *ctx, va_list va)
{
	wchar_t		c;
	uint32_t	len;

	c = va_arg(va, wchar_t);
	len = wclen(c);
	if (ctx->fwidth < len)
		ctx->fwidth = len;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		return (padded_putunicode(c, ctx->flags, ctx->fwidth - len));
	write(1, &c, 1);
	return (SUCCESS);
}

int	get_arg_c(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return (get_unicode(ctx, va));
	else
		return (get_char(ctx, va));
}
