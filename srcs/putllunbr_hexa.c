/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putllunbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:47:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/03 02:32:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	putllunbr_hexa(LLU n, char c)
{
	int		mod;
	char	d;

	if (n > 15)
		putllunbr_hexa(n / 16, c);
	mod = n % 16;
	if (mod > 9)
		d = mod - 10 + c;
	else
		d = mod + '0';
	write(1, &d, 1);
}
