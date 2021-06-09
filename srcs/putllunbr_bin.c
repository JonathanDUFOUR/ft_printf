/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putllunbr_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:54:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/03 02:31:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	putllunbr_bin(LLU n)
{
	char	d;

	if (n > 1)
		putllunbr_bin(n / 2);
	d = n % 2 + '0';
	write(1, &d, 1);
}
