/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:34:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/07 02:53:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "ft_printf.h"
#include "libft.h"

size_t	ft_va_count(char const *format)
{
	size_t	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++count;
			++format;
			while (!ft_strchr(CONVERT_SPEC, *format))
				++format;
		}
		++format;
	}
	return (count);
}
