/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:58:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/10 21:51:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static int	ft_clean_n_quit(int ret, char *print, va_list va)
{
	va_end(va);
	free(print);
	return (ret);
}

int	ft_printf(char const *format, ...)
{
	char		*print;
	int			len;
	va_list		va;

	print = NULL;
	va_start(va, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_manage_arg(format + 1, &print, va);
			if (!format)
				return (ft_clean_n_quit(MALLOC_ERRNO, print, va));
		}
		else
		{
			format = ft_manage_text(format, &print);
			if (!format)
				return (ft_clean_n_quit(MALLOC_ERRNO, print, va));
		}
	}
	len = (int)ft_strlen(print);
	write(1, print, len);
	return (ft_clean_n_quit(len, print, va));
}
