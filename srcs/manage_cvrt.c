/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cvrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:02:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:57:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "internal.h"
#include "lookup_cvrt.h"
#include "t_ctx.h"

char	*manage_cvrt(char const *format, t_ctx *const ctx, va_list va)
{
	int	i;

	format = parse_flags(format, ctx);
	if (!format)
		return (NULL);
	format = parse_fwidth(format, ctx, va);
	if (!format)
		return (NULL);
	format = parse_prec(format, ctx, va);
	if (!format)
		return (NULL);
	format = parse_lmod(format, ctx);
	if (!format)
		return (NULL);
	i = 0;
	while (g_cvrt[i].fct && g_cvrt[i].c != *format)
		++i;
	if (!g_cvrt[i].fct || g_cvrt[i].fct(ctx, va))
		return (NULL);
	return ((char *)format + 1);
}
