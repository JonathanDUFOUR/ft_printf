/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstrsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:18:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/06 17:50:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdint.h>

uint32_t	wclen(wchar_t c);

uint32_t	wstrsize(wchar_t *s)
{
	uint32_t	size;

	size = 0;
	while (*s)
		size += wclen(*s++);
	return (size);
}
