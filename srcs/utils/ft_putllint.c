/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 01:35:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:05:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_int.h"

void	ft_putllint(t_llint const nb)
{
	t_lluint	abs;
	char		digit;

	abs = (t_lluint)nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		abs = (t_lluint)(-nb);
	}
	if (abs > 9)
		ft_putllint(abs / 10);
	digit = abs % 10 + '0';
	write(1, &digit, 1);
}
