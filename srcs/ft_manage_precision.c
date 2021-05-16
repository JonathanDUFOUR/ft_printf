/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:21:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 16:55:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char const	*ft_manage_precision(char const *format, t_ctx *ctx, va_list va)
{
	int	tmp;

	if (*format == '.')
	{
		ctx->flags &= ~(1 << 1);
		if (*++format == '*')
		{
			tmp = va_arg(va, int);
			if (tmp >> 31)
				ctx->precision = 0;
			else
				ctx->precision = tmp;
			++format;
		}
		else
		{
			if (!ft_isdigit(*format))
				ctx->errors |= (1 << 2);
			ctx->precision = ft_atou(format);
			while (ft_isdigit(*format))
				++format;
		}
	}
	return (format);
}
