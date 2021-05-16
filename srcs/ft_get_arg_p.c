/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 08:32:23 by jodufour         ###   ########.fr       */
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

static char	*ft_add_padding(char *output, uint32_t padlen, int c, int side)
{
	if (side == LEFT)
	{
		*output-- = 'x';
		*output-- = '0';
	}
	while (padlen--)
		*output-- = c;
	if (side == RIGHT)
	{
		*output-- = 'x';
		*output-- = '0';
	}
	return (output);
}

static char	*ft_fill_output(char *output, uint64_t n, uint32_t precision)
{
	uint32_t	mod;

	while (precision--)
	{
		mod = n % 16;
		if (mod < 10)
			*output-- = mod + '0';
		else
			*output-- = mod - 10 + 'a';
		n /= 16;
	}
	return (output);
}

static char	*ft_padded_utop(uint64_t n, t_ctx *ctx)
{
	char		*output;
	uint32_t	len;

	len = ((ctx->precision + 2) > ctx->field_width) * (ctx->precision + 2)
		+ (ctx->field_width >= (ctx->precision + 2)) * ctx->field_width;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output += len;
	*output-- = 0;
	ctx->field_width = ft_get_padlen(ctx->field_width, ctx->precision + 2);
	if (ctx->flags & (1 << 0))
		output = ft_add_padding(output, ctx->field_width, ' ', NONE);
	output = ft_fill_output(output, n, ctx->precision);
	if (!(ctx->flags & (1 << 0)))
	{
		if (ctx->flags & (1 << 1))
			output = ft_add_padding(output, ctx->field_width, '0', RIGHT);
		else
			output = ft_add_padding(output, ctx->field_width, ' ', LEFT);
		return (++output);
	}
	*output-- = 'x';
	*output-- = '0';
	return (++output);
}

char	*ft_get_arg_p(t_ctx *ctx, va_list va)
{
	uint64_t	n;
	uint32_t	digits;
	char		*output;
	char		*dent;

	n = va_arg(va, uint64_t);
	digits = ft_plen(n);
	if (digits > ctx->precision)
		ctx->precision = digits;
	dent = ft_padded_utop(n, ctx);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	free(dent);
	return (output);
}
