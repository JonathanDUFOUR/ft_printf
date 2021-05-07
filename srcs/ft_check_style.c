/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_style.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 02:01:54 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/07 05:07:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

static char const	*check_conversion(int *const counts, const char *format)
{
	while (*format && ft_isdigit(*format))
		++format;
	if (*format == '$')
		++counts[DOLLAR];
	while (*format && !ft_strchr(CONVERT_SPEC, *format))
	{
		if (*format == '*')
		{
			++counts[STAR];
			++format;
			while (*format && ft_isdigit(*format))
				++format;
			if (*format == '$')
				++counts[DOLLAR];
		}
		++format;
	}
	return (format);
}

int	ft_check_style(char const *format)
{
	int	counts[3];

	ft_bzero(counts, sizeof(counts));
	while (*format)
	{
		if (*format == '%')
		{
			++counts[POURCENT];
			format = check_conversion(counts, format + 1);
		}
		++format;
	}
	if (!counts[DOLLAR])
		return (SIMPLE_STYLE);
	else if (counts[DOLLAR] == (counts[POURCENT] + counts[STAR]))
		return (DOLLAR_STYLE);
	return (STYLE_ERRNO);
}
