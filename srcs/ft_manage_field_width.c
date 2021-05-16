/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_field_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:43:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 05:56:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char const	*ft_manage_field_width(char const *format, t_ctx *ctx, va_list va)
{
	int	tmp;

	if (*format == '*')
	{
		tmp = va_arg(va, int);
		if (tmp >> 31)
		{
			ctx->flags |= 1 << 0;
			ctx->flags &= ~(1 << 1);
			ctx->field_width = -tmp;
		}
		else
			ctx->field_width = tmp;
		++format;
	}
	else
	{
		ctx->field_width = ft_atou(format);
		while (ft_isdigit(*format))
			++format;
	}
	return (format);
}
