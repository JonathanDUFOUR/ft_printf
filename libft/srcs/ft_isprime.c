/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:11:43 by jonathan          #+#    #+#             */
/*   Updated: 2021/05/25 22:39:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isprime(uint32_t n)
{
	uint32_t	i;

	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
		return (true);
	if (n < 2 || !(n % 2) || !(n % 3) || !(n % 5) || !(n % 7) || !(n % 11))
		return (false);
	i = 13;
	while (i < (n / 10))
	{
		if (!(n % i))
			return (false);
		i += 2;
	}
	return (true);
}