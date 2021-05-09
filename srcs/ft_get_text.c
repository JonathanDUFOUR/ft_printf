/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:18:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/09 06:42:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_get_text(char const *format, char *print)
{
	char	*output;
	char	*dent;
	char	*next;

	next = ft_strchr(format, '%');
	if (next)
		dent = ft_strndup(format, next - format);
	else
		dent = ft_strdup(format);
	output = ft_strjoin(print, dent);
	free(dent);
	return (output);
}
