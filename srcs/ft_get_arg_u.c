/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 14:53:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_get_arg_u(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	uint32_t	digits;

	n = va_arg(va, uint32_t);
	digits = ft_uintlen(n);
	if (digits > ctx->precision)
		ctx->precision = digits;
	return (SUCCESS);
}
