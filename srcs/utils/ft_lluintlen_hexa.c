/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluintlen_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 07:30:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/11 10:38:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

int	ft_lluintlen_hexa(t_lluint nb)
{
	int	len;

	len = 1;
	while (nb > 15)
	{
		++len;
		nb /= 16;
	}
	return (len);
}
