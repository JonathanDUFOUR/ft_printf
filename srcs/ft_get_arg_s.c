/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 14:53:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_get_arg_s(t_ctx *ctx, va_list va)
{
	char		*s;
	uint32_t	len;

	s = va_arg(va, char *);
	len = (uint32_t)ft_strlen(s);
	if (ctx->precision > len)
		ctx->precision = len;
	return (SUCCESS);
}
