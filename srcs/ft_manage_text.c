/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:37:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 00:57:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char const	*ft_manage_text(char const *format, t_ctx *ctx)
{
	char	*dent;

	dent = ctx->print;
	ctx->print = ft_get_text(format, ctx->print);
	free(dent);
	if (!ctx->print)
		return (NULL);
	while (*format && *format != '%')
		++format;
	return (format);
}
