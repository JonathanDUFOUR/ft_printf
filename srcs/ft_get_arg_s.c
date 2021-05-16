/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 09:31:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static char	*ft_padded_str(char *s, t_ctx *ctx)
{
	char		*output;
	char		*p;
	uint32_t	len;

	len = (ctx->precision > ctx->field_width) * ctx->precision
		+ (ctx->precision <= ctx->field_width) * ctx->field_width;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	if (ctx->field_width > ctx->precision)
		ctx->field_width -= ctx->precision;
	else
		ctx->field_width = 0;
	p = output;
	if (!(ctx->flags & (1 << 0)))
		while (ctx->field_width--)
			*p++ = ' ';
	while (ctx->precision--)
		*p++ = *s++;
	if (ctx->flags & (1 << 0))
		while (ctx->field_width--)
			*p++ = ' ';
	*p = 0;
	return (output);
}

char	*ft_get_arg_s(t_ctx *ctx, va_list va)
{
	char		*s;
	char		*output;
	char		*dent;
	uint32_t	len;

	s = va_arg(va, char *);
	len = (uint32_t)ft_strlen(s);
	if (ctx->precision > len)
		ctx->precision = len;
	dent = ft_padded_str(s, ctx);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	free(dent);
	return (output);
}
