/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:29:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/17 13:15:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static int	ft_padded_putchar(int c, uint8_t flags, uint32_t field_width)
{
	if (!(flags & (1 << 0)) && ft_padding(' ', field_width - 1) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	write(1, &c, 1);
	if (flags & (1 << 0) && ft_padding(' ', field_width - 1) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}

int	ft_get_arg_c(t_ctx *ctx, va_list va)
{
	int		c;

	c = va_arg(va, int);
	if (!ctx->field_width)
		ctx->field_width = 1;
	ctx->len += ctx->field_width;
	if (ctx->field_width > 1)
		return (ft_padded_putchar(c, ctx->flags, ctx->field_width));
	ft_putchar(c);
	return (SUCCESS);
}
