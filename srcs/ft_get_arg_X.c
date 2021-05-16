/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 06:38:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static uint32_t	ft_get_padlen(uint32_t field_width, uint32_t precision)
{
	if (field_width > precision)
		return (field_width - precision);
	return (0);
}

static char	*ft_add_padding(char *output, uint32_t padlen, int c)
{
	while (padlen--)
		*output-- = c;
	return (output);
}

static char	*ft_fill_output(char *output, uint32_t n, uint32_t precision)
{
	uint32_t	mod;

	while (precision--)
	{
		mod = n % 16;
		if (mod < 10)
			*output-- = mod + '0';
		else
			*output-- = mod - 10 + 'A';
		n /= 16;
	}
	return (output);
}

static char	*ft_padded_utoX(uint32_t n, t_ctx *ctx)
{
	char		*output;
	uint32_t	len;

	len = (ctx->precision > ctx->field_width) * ctx->precision
		+ (ctx->field_width >= ctx->precision) * ctx->field_width;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output += len;
	*output-- = 0;
	ctx->field_width = ft_get_padlen(ctx->field_width, ctx->precision);
	if (ctx->flags & (1 << 0))
		output = ft_add_padding(output, ctx->field_width, ' ');
	output = ft_fill_output(output, n, ctx->precision);
	if (!(ctx->flags & (1 << 0)))
	{
		if (ctx->flags & (1 << 1))
			output = ft_add_padding(output, ctx->field_width, '0');
		else
			output = ft_add_padding(output, ctx->field_width, ' ');
	}
	return (++output);
}

char	*ft_get_arg_x(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	uint32_t	digits;
	char		*output;
	char		*dent;

	n = va_arg(va, uint32_t);
	digits = ft_xlen(n);
	if (digits > ctx->precision)
		ctx->precision = digits;
	dent = ft_padded_utoX(n, ctx);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	free(dent);
	return (output);
}
