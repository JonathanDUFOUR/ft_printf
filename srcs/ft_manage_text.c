/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:37:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 11:35:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char const	*ft_manage_text(char const *format, t_ctx *ctx)
{
	char	*next;

	next = ft_strchr(format, '%');
	if (next)
	{
		ctx->field_width = next - format;
	}
	else
	{
		ctx->field_width = ft_strlen(format);
	}
	write(1, format, ctx->field_width);
	ctx->len += ctx->field_width;
	while (*format && *format != '%')
		++format;
	return (format);
}
