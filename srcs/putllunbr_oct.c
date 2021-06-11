/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putllunbr_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 01:52:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/03 02:32:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	putllunbr_oct(LLU n)
{
	char	d;

	if (n > 7)
		putllunbr_oct(n / 8);
	d = n % 8 + '0';
	write(1, &d, 1);
}
