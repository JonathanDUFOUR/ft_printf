/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_field_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:43:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 23:55:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char const	*ft_manage_field_width(char const *format, t_ctx *ctx, va_list va)
{
	if (*format == '*')
	{
		ctx->field_width = va_arg(va, uint32_t);
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
