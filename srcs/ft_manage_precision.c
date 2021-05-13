/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:21:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/13 16:48:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char const	*ft_manage_precision(char const *format, t_ctx *ctx, va_list va)
{
	if (*format == '.')
	{
		if (*++format == '*')
		{
			ctx->precision = va_arg(va, uint32_t);
			++format;
		}
		else
		{
			ctx->precision = ft_atou(format);
			while (ft_isdigit(*format))
				++format;
		}
	}
	return (format);
}
