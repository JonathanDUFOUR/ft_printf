/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 03:15:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/14 02:22:50 by jodufour         ###   ########.fr       */
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
	ft_putstr("flags       -> ");
	ft_putbyte(ctx->flags);
	printf("\nfield_width -> %u\n", ctx->field_width);
	printf("precision   -> %u\n", ctx->precision);
	format = ft_manage_specifier(format, ctx, va);
	return (format);
}
