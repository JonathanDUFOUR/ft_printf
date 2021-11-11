/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluintlen_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:36:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/10 17:37:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

int	ft_lluintlen_oct(t_lluint nb)
{
	int	len;

	len = 1;
	while (nb > 7)
	{
		++len;
		nb /= 8;
	}
	return (len);
}
