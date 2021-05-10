/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/10 02:26:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

char	*ft_get_arg_X(char *print, va_list va)
{
	uint32_t	X;
	char		*output;
	char		*dent;

	X = va_arg(va, uint32_t);
	dent = ft_utoa_base(X, "0123456789ABCDEF");
	if (!dent)
		return (NULL);
	output = ft_strjoin(print, dent);
	free(dent);
	return (output);
}
