/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 12:16:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_padded_putnbr(int n, uint32_t intlen, t_ctx *ctx)
{
	if (ctx->precision < intlen)
		ctx->precision
	return (SUCCESS);
}

int	ft_get_arg_d_i(t_ctx *ctx, va_list va)
{
	int			n;
	uint32_t	intlen;

	n = va_arg(va, uint32_t);
	intlen = ft_intlen(n);
	if (!ctx->field_width)
		ctx->field_width = intlen;
	ctx->len += ctx->field_width;
	if (ctx->field_width > intlen)
		return (ft_padded_putnbr(n, intlen, ctx));
	ft_putnbr(n);
	return (SUCCESS);
	
}
