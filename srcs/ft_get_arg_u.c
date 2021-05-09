/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/09 06:02:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

char	*ft_get_arg_u(char *print, va_list va)
{
	uint32_t	n;
	char		*output;
	char		*dent;

	n = va_arg(va, uint32_t);
	dent = ft_utoa(n);
	if (!dent)
		return (NULL);
	output = ft_strjoin(print, dent);
	free(dent);
	return (output);
}
