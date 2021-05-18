/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_c_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:29:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:30:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static int	padded_putchar(int c, uint8_t flags, uint32_t field_width)
{
	if (!(flags & (1 << 0)) && padding(' ', field_width - 1) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, &c, 1);
	if (flags & (1 << 0) && padding(' ', field_width - 1) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}

int	get_arg_c_lower(t_ctx *ctx, va_list va)
{
	int		c;

	c = va_arg(va, int);
	if (!ctx->fwidth)
		ctx->fwidth = 1;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		return (padded_putchar(c, ctx->flags, ctx->fwidth));
	putchar(c);
	return (SUCCESS);
}
