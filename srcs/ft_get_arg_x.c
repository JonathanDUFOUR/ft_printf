/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 22:29:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char	*ft_get_arg_x(t_ctx *ctx, va_list va)
{
	uint32_t	x;
	char		*output;
	char		*dent;

	x = va_arg(va, uint32_t);
	dent = ft_utoa_base(x, "0123456789abcdef");
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	free(dent);
	return (output);
}
