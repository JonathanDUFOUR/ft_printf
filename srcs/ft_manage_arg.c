/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 03:15:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 03:24:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char const	*ft_manage_arg(char const *format, t_ctx *ctx, va_list va)
{
	format = ft_manage_flags(format, ctx, va);
	printf("field_width -> %u\n", ctx->field_width);
	printf("padding     -> '%c'\n", ctx->padding);
	ft_putstr("flags       -> ");
	ft_putbyte(ctx->flags);
	printf("\n");
	format = ft_manage_spec(format, ctx, va);
	return (format);
}
