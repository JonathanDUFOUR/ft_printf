/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlluint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:05:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/10 16:31:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type/t_int.h"

void	ft_putlluint(t_lluint const nb)
{
	char	digit;

	if (nb > 9)
		ft_putlluint(nb / 10);
	digit = nb % 10 + '0';
	write(1, &digit, 1);
}
