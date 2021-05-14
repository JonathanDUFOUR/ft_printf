/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:29:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/14 03:20:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

char	*ft_padded_ctoa(int c, int field_width, int side)
{
	char	*output;
	char	*p;

	output = malloc((field_width + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output;
	if (side == RIGHT)
		*p++ = c;
	while (--field_width)
		*p++ = ' ';
	if (side == LEFT)
		*p++ = c;
	*p = 0;
	return (output);
}

char	*ft_get_arg_c(t_ctx *ctx, va_list va)
{
	char	c;
	char	*output;
	char	*dent;

	c = va_arg(va, int);
	if (ctx->field_width)
		dent = ft_padded_ctoa(c, ctx->field_width, ctx->flags & (1 << 0));
	else
		dent = ft_ctoa(c);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	free(dent);
	return (output);
}
