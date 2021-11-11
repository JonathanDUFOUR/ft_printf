/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstrlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:39:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/10 17:56:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int	ft_wstrlen(wchar_t const *str)
{
	register wchar_t const	*ptr = str;

	while (*ptr)
		++ptr;
	return (ptr - str);
}
