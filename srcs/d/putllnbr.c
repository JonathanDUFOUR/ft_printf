/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putllnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 01:35:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/02 01:49:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putllnbr(long long int n)
{
	unsigned long long int	abs;
	char					d;

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
