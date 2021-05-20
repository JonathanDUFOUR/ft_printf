/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:21:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:16:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char const	*manage_precision(char const *format, t_ctx *ctx, va_list va)
{
	if (*format == '.')
	{
		if (*++format == '*')
		{
			ctx->prec = va_arg(va, uint32_t);
			if (ctx->prec >> 31)
				ctx->prec = 1;
			else
			{
				ctx->precised = true;
				ctx->flags &= ~(1 << 1);
			}
			++format;
		}
		else
		{
			ctx->precised = true;
			ctx->flags &= ~(1 << 1);
			ctx->prec = ft_atou(format);
			while (ft_isdigit(*format))
				++format;
		}
	}
	return (format);
}
