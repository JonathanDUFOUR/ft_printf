/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:58:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/07 05:08:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list		va;
	size_t		va_count;
	t_unival	*values;
	int			ret;

	va_count = ft_va_count(format);
	ret = ft_check_style(format);
	if (ret == SIMPLE_STYLE)
	{
	}
	else if (ret == DOLLAR_STYLE)
	{
	}
	else
		return (STYLE_ERRNO);
	return (42);
}
