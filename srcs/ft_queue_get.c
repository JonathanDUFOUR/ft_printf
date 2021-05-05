/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:38:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 03:17:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_queue_get(t_queue **queue, char const *format)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!ft_strchr(CV_CHARS, *(++format)))
				return (CV_ERRNO);
			*queue = ft_queue_add_back(*queue, *format);
			if (!*queue)
				return (MALLOC_ERRNO);
			++count;
		}
		++format;
	}
	return (count);
}
