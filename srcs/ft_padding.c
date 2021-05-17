/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:10:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/17 13:17:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_padding(int c, uint32_t padlen)
{
	char	*padding;
	char	*p;

	padding = malloc((padlen + 1) * sizeof(char));
	if (!padding)
		return (MALLOC_ERRNO);
	p = padding;
	while (padlen--)
		*p++ = c;
	*p = 0;
	write(1, padding, p - padding);
	free(padding);
	return (SUCCESS);
}
