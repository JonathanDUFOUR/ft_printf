/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlluint_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:47:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/10 16:31:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type/t_int.h"

void	ft_putlluint_hexa(t_lluint const nb, char const c)
{
	int		mod;
	char	digit;

	if (nb > 15)
		ft_putlluint_hexa(nb / 16, c);
	mod = nb % 16;
	if (mod > 9)
		digit = mod - 10 + c;
	else
		digit = mod + '0';
	write(1, &digit, 1);
}
