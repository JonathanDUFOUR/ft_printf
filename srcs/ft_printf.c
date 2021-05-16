/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:58:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 11:52:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static t_ctx	*ft_init_ctx(void)
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		return (NULL);
	ctx->len = 0;
	ctx->flags = 0;
	ctx->field_width = 0;
	ctx->precision = 0;
	return (ctx);
}

static int	ft_clean_n_quit(int ret, t_ctx *ctx, va_list va)
{
	va_end(va);
	free(ctx);
	return (ret);
}

int	ft_printf(char const *format, ...)
{
	t_ctx		*ctx;
	va_list		va;

	ctx = ft_init_ctx();
	if (!ctx)
		return (MALLOC_ERRNO);
	va_start(va, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_manage_arg(format + 1, ctx, va);
		else
			format = ft_manage_text(format, ctx);
		if (!format)
			return (ft_clean_n_quit(MALLOC_ERRNO, ctx, va));
	}
	printf("ctx->len == %u\n", ctx->len);
	return (ft_clean_n_quit((int)ctx->len, ctx, va));
}
