/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_dispatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 01:17:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/02 01:24:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_arg_d(t_ctx *ctx, va_list va);
int	get_arg_hd(t_ctx *ctx, va_list va);
int	get_arg_hhd(t_ctx *ctx, va_list va);
int	get_arg_ld(t_ctx *ctx, va_list va);
int	get_arg_lld(t_ctx *ctx, va_list va);

int	d_dispatch(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return (get_arg_ld(ctx, va));
	else if (ctx->flags & (1 << 6))
		return (get_arg_lld(ctx, va));
	else if (ctx->flags & (1 << 7))
		return (get_arg_hd(ctx, va));
	else if (ctx->flags & (1 << 8))
		return (get_arg_hhd(ctx, va));
	else
		return (get_arg_d(ctx, va));
}
