/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lmod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:12:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:05:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_ctx.h"

char	*parse_lmod(char const *format, t_ctx *ctx)
{
	if (*format == 'l')
	{
		++format;
		if (*format == 'l' && ++format)
			ctx->flags |= 1 << 6;
		else
			ctx->flags |= 1 << 5;
	}
	else if (*format == 'h')
	{
		++format;
		if (*format == 'h' && ++format)
			ctx->flags |= 1 << 8;
		else
			ctx->flags |= 1 << 7;
	}
	return ((char *)format);
}
