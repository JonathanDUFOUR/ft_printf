/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:29:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 22:25:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

char	*ft_get_arg_c(t_ctx *ctx, va_list va)
{
	char	c;
	char	*output;
	char	*dent;

	c = va_arg(va, int);
	dent = ft_ctoa(c);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	free(dent);
	return (output);
}
