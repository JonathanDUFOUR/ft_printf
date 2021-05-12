/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:58:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 21:45:38 by jodufour         ###   ########.fr       */
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
	ctx->print = NULL;
	ctx->flags = 0;
	ctx->padding = 0;
	ctx->field_width = 0;
	return (ctx);
}

static int	ft_clean_n_quit(int ret, t_ctx *ctx, va_list va)
{
	va_end(va);
	free(ctx->print);
	free(ctx);
	return (ret);
}

int	ft_printf(char const *format, ...)
{
	t_ctx		*ctx;
	va_list		va;
	int			len;

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
	len = (int)ft_strlen(ctx->print);
	write(1, ctx->print, len);
	return (ft_clean_n_quit(len, ctx, va));
}
