/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putllnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 01:35:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/03 01:55:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	putllnbr(LLD n)
{
	LLU		abs;
	char	d;

	abs = n;
	if (n < 0)
	{
		write(1, "-", 1);
		abs = -n;
	}
	if (abs > 9)
		putllnbr(abs / 10);
	d = abs % 10 + '0';
	write(1, &d, 1);
}
