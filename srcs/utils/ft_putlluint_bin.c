/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlluint_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:38:35 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/10 16:38:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type/t_int.h"

void	ft_putlluint_bin(t_lluint const nb)
{
	char	digit;

	if (nb > 1)
		ft_putlluint_bin(nb / 2);
	digit = nb % 2 + '0';
	write(1, &digit, 1);
}
