/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:20:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/09 04:33:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

char const	*ft_manage_spec(char const *format, char **to_print, va_list va)
{
	if (*format == 'c')
		ft_get_arg_c(to_print, va);
	else if (*format == 's')
		ft_get_arg_s(to_print, va);
	else if (*format == 'p')
		ft_get_arg_p(to_print, va);
	else if (*format == 'd' || *format == 'i')
		ft_get_arg_d_i(to_print, va);
	else if (*format == 'u')
		ft_get_arg_u(to_print, va);
	else if (*format == 'x')
		ft_get_arg_x(to_print, va);
	else if (*format == 'X')
		ft_get_arg_X(to_print, va);
	else if (*format == '%')
		;
	return (format + 1);
}
