/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:37:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 03:33:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

char const	*ft_manage_text(char const *format, t_ctx *ctx)
{
	char	*next;

	next = ft_strchr(format, '%');
	if (next)
	{
		ctx->fwidth = next - format;
	}
	else
	{
		ctx->fwidth = ft_strlen(format);
	}
	write(1, format, ctx->fwidth);
	ctx->len += ctx->fwidth;
	while (*format && *format != '%')
		++format;
	return (format);
}
