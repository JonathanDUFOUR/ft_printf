/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 03:15:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/17 15:56:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char const	*ft_manage_arg(char const *format, t_ctx *ctx, va_list va)
{
	format = ft_manage_flags(format, ctx);
	format = ft_manage_field_width(format, ctx, va);
	format = ft_manage_precision(format, ctx, va);
	format = ft_manage_specifier(format, ctx, va);
	ctx->flags = 0;
	ctx->field_width = 0;
	ctx->precision = 1;
	ctx->precised = false;
	return (format);
}
