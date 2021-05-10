/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:37:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/10 21:53:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char const	*ft_manage_text(char const *format, char **print)
{
	char	*dent;

	dent = *print;
	*print = ft_get_text(format, *print);
	free(dent);
	if (!*print)
		return (NULL);
	while (*format && *format != '%')
		++format;
	return (format);
}
