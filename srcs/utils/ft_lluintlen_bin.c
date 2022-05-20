/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluintlen_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:10:24 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:05:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"

int	ft_lluintlen_bin(t_lluint nb)
{
	int	len;

	len = 1;
	while (nb > 1)
	{
		++len;
		nb /= 2;
	}
	return (len);
}