/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:10:40 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:20:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "e_ret.h"

int	padding(int const c, int padlen)
{
	char	*padding;
	char	*ptr;

	padding = malloc((padlen + 1) * sizeof(char));
	if (!padding)
		return (MALLOC_ERR);
	ptr = padding;
	while (padlen--)
		*ptr++ = c;
	*ptr = 0;
	write(1, padding, ptr - padding);
	free(padding);
	return (SUCCESS);
}
