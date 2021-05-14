/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:21:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/14 15:22:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_right_padding(char *output, char *dent, int c, int field_width)
{
	int		padlen;
	char	*padding;
	char	*p;

	padlen = field_width - (int)ft_strlen(dent);
	if (padlen > 0)
	{
		padding = malloc((padlen + 1) * sizeof(char));
		if (!padding)
		{
			free(output);
			return (NULL);
		}
		p = padding;
		while (padlen--)
			*p++ = c;
		*p = 0;
		p = output;
		output = ft_strjoin(output, padding);
		free(p);
		free(padding);
	}
	return (output);
}
