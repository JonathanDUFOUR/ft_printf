/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/12 22:27:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char	*ft_get_arg_p(t_ctx *ctx, va_list va)
{
	void	*p;
	char	*output;
	char	*dent;

	p = va_arg(va, void *);
	output = ft_lutoa_base((uint64_t)p, "0123456789abcdef");
	if (!output)
		return (NULL);
	dent = ft_strjoin("0x", output);
	free(output);
	if (!dent)
		return (NULL);
	output = ft_strjoin(ctx->print, dent);
	free(dent);
	return (output);
}
