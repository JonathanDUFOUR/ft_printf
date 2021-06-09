/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_exception.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:11:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/02 16:14:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	flag_exception(t_ctx *ctx)
{
	if (ctx->flags & (1 << 2))
		write(1, "+", 1);
	else if (ctx->flags & (1 << 3))
		write(1, " ", 1);
	if (ctx->fwidth)
		--ctx->fwidth;
	++ctx->len;
}
