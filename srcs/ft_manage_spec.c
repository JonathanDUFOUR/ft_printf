/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:20:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/09 06:58:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

char const	*ft_manage_spec(char const *format, char **print, va_list va)
{
	char const	*dent = *print;

	if (*format == 'c')
		*print = ft_get_arg_c(*print, va);
	else if (*format == 's')
		*print = ft_get_arg_s(*print, va);
	else if (*format == 'p')
		*print = ft_get_arg_p(*print, va);
	else if (*format == 'd' || *format == 'i')
		*print = ft_get_arg_d_i(*print, va);
	else if (*format == 'u')
		*print = ft_get_arg_u(*print, va);
	else if (*format == 'x')
		*print = ft_get_arg_x(*print, va);
	else if (*format == 'X')
		*print = ft_get_arg_X(*print, va);
	else if (*format == '%')
		*print = ft_get_arg_prct(*print);
	free((char *)dent);
	if (!*print)
		return (NULL);
	return (format + 1);
}
