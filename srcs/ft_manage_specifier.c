/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:20:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 03:34:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

char const	*ft_manage_specifier(char const *format, t_ctx *ctx, va_list va)
{
	int	ret;

	if (*format == 'c')
		ret = ft_get_arg_c(ctx, va);
	else if (*format == 's')
		ret = ft_get_arg_s(ctx, va);
	else if (*format == 'p')
		ret = ft_get_arg_p(ctx, va);
	else if (*format == 'd' || *format == 'i')
		ret = ft_get_arg_d_i(ctx, va);
	else if (*format == 'u')
		ret = ft_get_arg_u(ctx, va);
	else if (*format == 'x')
		ret = ft_get_arg_x(ctx, va);
	else if (*format == 'X')
		ret = ft_get_arg_X(ctx, va);
	else if (*format == 'o')
		ret = ft_get_arg_o(ctx, va);
	else if (*format == 'b')
		ret = ft_get_arg_b(ctx, va);
	else if (*format == '%')
		ret = ft_get_arg_prct(ctx);
	if (ret != SUCCESS)
		return (NULL);
	return (format + 1);
}
