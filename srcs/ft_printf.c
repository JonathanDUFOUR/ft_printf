/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:58:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:30:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static void	init_ctx(t_ctx *ctx)
{
	ctx->len = 0;
	ctx->flags = 0;
	ctx->fwidth = 0;
	ctx->prec = 1;
	ctx->precised = false;
}

int	ft_printf(char const *format, ...)
{
	t_ctx		ctx;
	va_list		va;

	init_ctx(&ctx);
	va_start(va, format);
	while (*format)
	{
		if (*format == '%')
			format = manage_arg(format + 1, &ctx, va);
		else
			format = manage_text(format, &ctx);
		if (!format)
		{
			va_end(va);
			return (MALLOC_ERRNO);
		}
	}
	va_end(va);
	return ((int)ctx.len);
}
