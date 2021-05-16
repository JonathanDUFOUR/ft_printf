/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:43:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 12:35:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

char	*ft_get_padding(int c, uint32_t padlen)
{
	char	*padding;
	char	*p;

	padding = malloc((padlen + 1) * sizeof(char));
	if (!padding)
		return (NULL);
	p = padding;
	while (padlen--)
		*p++ = c;
	*p = 0;
	return (padding);
}
