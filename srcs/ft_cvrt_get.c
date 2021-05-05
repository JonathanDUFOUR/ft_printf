/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvrt_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:38:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 02:42:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_cvrt_get(t_cvrt **cv, char const *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (!ft_strchr(CV_CHARS, *(++format)))
				return (CV_ERRNO);
			*cv = ft_cvrt_add_back(*cv, *format);
			if (!*cv)
				return (MALLOC_ERRNO);
		}
		++format;
	}
	return (SUCCESS);
}
