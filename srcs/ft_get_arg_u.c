/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 22:29:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char	*ft_get_arg_u(t_ctx *ctx, va_list va)
{
	uint32_t	n;
	char		*output;
	char		*dent;

	n = va_arg(va, uint32_t);
	dent = ft_utoa(n);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	free(dent);
	return (output);
}
