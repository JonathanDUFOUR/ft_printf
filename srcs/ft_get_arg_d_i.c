/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/09 05:55:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

char	*ft_get_arg_d_i(char *print, va_list va)
{
	int		n;
	char	*output;
	char	*dent;

	n = va_arg(va, int);
	dent = ft_itoa(n);
	if (!dent)
		return (NULL);
	output = ft_strjoin(print, dent);
	free(dent);
	return (output);
}
