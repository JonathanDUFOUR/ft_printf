/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:39:47 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/02 17:20:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint32_t	ulen(LLU n)
{
	uint32_t	len;

	len = 1;
	n /= 10;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}
