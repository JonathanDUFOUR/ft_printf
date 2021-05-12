/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:38:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 03:24:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

/*
**	0	The value should be zero padded.
**		For d, i, o, u, x, X, a, A, e, E, f, F, g, and G conversions, the
**		converted value is padded on the left with zeros rather than blanks.
**		If the 0 and - flags both appear, the 0 flag is ignored.
**		If a precision is given with a numeric conversion (d, i, o, u, x, and X)
**		the 0 flag is ignored.
**		For other conversions, the behavior is undefined.
**
**	-	The  converted  value  is  to be left adjusted on the field boundary.
**		(The default is right justification.)
**		The converted value is padded on the right with blanks,
**		rather than on the left with blanks  or zeros.
**		A - overrides a 0 if both are given.
*/
char const	*ft_manage_flags(char const *format, t_ctx *ctx, va_list va)
{
	(void)va;
	while (*format && ft_strchr(FLAG_CHARS, *format))
	{
		if (*format == '-')
		{
			ctx->flags |= 1 << 0;
			++format;
		}
		else if (*format == '0' && !(ctx->flags & 1 << 0))
		{
			ctx->flags |= 1 << 1;
			ctx->padding = '0';
			ctx->field_width = ft_atou(format);
			while (ft_isdigit(*format))
				++format;
		}
		else
			++format;
	}
	return (format);
}
