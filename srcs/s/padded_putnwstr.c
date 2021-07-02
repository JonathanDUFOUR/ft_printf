/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded_putnwstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:03:18 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/02 14:49:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "e_ret.h"

int	padded_putnwstr(wchar_t *s, t_ctx *ctx, uint32_t len, uint32_t size)
{
	len = ctx->prec;
	if (!(ctx->flags & (1 << 0))
		&& padding(' ', ctx->fwidth - size) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	while (len--)
		if (ft_putchar(*s++) == -1)
			return (WRITE_ERRNO);
	if (ctx->flags & (1 << 0)
		&& padding(' ', ctx->fwidth - size) == MALLOC_ERRNO)
		return (MALLOC_ERRNO);
	return (SUCCESS);
}
