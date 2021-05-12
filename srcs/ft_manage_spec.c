/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:20:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 00:57:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

char const	*ft_manage_spec(char const *format, t_ctx *ctx, va_list va)
{
	char	*dent;

	dent = ctx->print;
	if (*format == 'c')
		ctx->print = ft_get_arg_c(ctx->print, va);
	else if (*format == 's')
		ctx->print = ft_get_arg_s(ctx->print, va);
	else if (*format == 'p')
		ctx->print = ft_get_arg_p(ctx->print, va);
	else if (*format == 'd' || *format == 'i')
		ctx->print = ft_get_arg_d_i(ctx->print, va);
	else if (*format == 'u')
		ctx->print = ft_get_arg_u(ctx->print, va);
	else if (*format == 'x')
		ctx->print = ft_get_arg_x(ctx->print, va);
	else if (*format == 'X')
		ctx->print = ft_get_arg_X(ctx->print, va);
	else if (*format == '%')
		ctx->print = ft_get_arg_prct(ctx->print);
	free(dent);
	if (!ctx->print)
		return (NULL);
	return (format + 1);
}
