/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:34:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 22:03:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

ssize_t	ft_va_count(char const *format)
{
	ssize_t	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
		}
		++format;
	}
	return (count);
}
