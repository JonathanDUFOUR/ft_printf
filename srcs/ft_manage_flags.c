/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:38:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 23:57:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char const	*ft_manage_flags(char const *format, t_ctx *ctx)
{
	while (*format && ft_strchr(FLAG_CHARS, *format))
	{
		if (*format == '-')
		{
			ctx->flags |= 1 << 0;
			ctx->padding = ' ';
		}
		else if (*format == '0' && !(ctx->flags & (1 << 0)))
		{
			ctx->flags |= 1 << 1;
			ctx->padding = '0';
		}
		++format;
	}
	return (format);
}