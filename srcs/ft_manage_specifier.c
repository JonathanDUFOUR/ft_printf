/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:20:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 04:34:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "dispatch_lookup.h"

char const	*ft_manage_specifier(char const *format, t_ctx *ctx, va_list va)
{
	t_cvrt const	*curr;

	curr = g_cvrt;
	while (curr->c && curr->c != *format)
		++curr;
	if (!curr->fct || curr->fct(ctx, va) != SUCCESS)
		return (NULL);
	return (format + 1);
}
