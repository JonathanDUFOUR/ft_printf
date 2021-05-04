/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:38:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/04 04:04:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_cv_get(t_cv **cv, char const *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (!ft_strchr(CV_CHARS, *(++format)))
				return (CV_ERRNO);
			*cv = ft_cv_add_back(*cv, *format);
			if (!*cv)
				return (MALLOC_ERRNO);
		}
		++format;
	}
	return (SUCCESS);
}
