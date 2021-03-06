/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:18:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/11 10:39:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	ft_wstrsize(wchar_t const *str)
{
	int	size;

	size = 0;
	while (*str)
		size += ft_wclen(*str++);
	return (size);
}
