/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:37:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/03 03:04:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

char const	*manage_text(char const *format, t_ctx *ctx)
{
	char	*next;

	next = ft_strchr(format, '%');
	if (next)
		ctx->fwidth = next - format;
	else
		ctx->fwidth = ft_strlen(format);
	write(1, format, ctx->fwidth);
	ctx->len += ctx->fwidth;
	while (*format && *format != '%')
		++format;
	return (format);
}
