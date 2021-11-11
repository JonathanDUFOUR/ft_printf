/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlluint_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:52:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/10 16:31:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type/t_int.h"

void	ft_putlluint_oct(t_lluint const nb)
{
	char	digit;

	if (nb > 7)
		ft_putlluint_oct(nb / 8);
	digit = nb % 8 + '0';
	write(1, &digit, 1);
}
