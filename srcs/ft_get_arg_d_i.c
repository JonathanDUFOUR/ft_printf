/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/16 06:36:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static char	*ft_padded_itoa(int n, int c, uint32_t padlen)
{
	uint32_t	abs;
	uint32_t	len;
	char		*output;
	char		*p;

	len = ft_intlen(n) + padlen;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output + len;
	*p-- = 0;
	abs = n;
	if (n >> 31 && --len)
	{
		*output = '-';
		abs = -n;
	}
	while (abs && --len)
	{
		*p-- = (abs % 10) + '0';
		abs /= 10;
	}
	while (len--)
		*p-- = c;
	return (output);
}

char	*ft_get_arg_d_i(t_ctx *ctx, va_list va)
{
	int			n;
	uint32_t	digits;
	char		*output;
	char		*dent;

	n = va_arg(va, int);
	digits = ft_intlen(n) - (n < 0);
	output = NULL;
	return (output);
}
