/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_lookup.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 04:09:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 04:36:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_LOOKUP_H
# define DISPATCH_LOOKUP_H

# include "t_cvrt.h"

int	ft_get_arg_c(t_ctx *ctx, va_list va);
int	ft_get_arg_s(t_ctx *ctx, va_list va);
int	ft_get_arg_p(t_ctx *ctx, va_list va);
int	ft_get_arg_d_i(t_ctx *ctx, va_list va);
int	ft_get_arg_u(t_ctx *ctx, va_list va);
int	ft_get_arg_x(t_ctx *ctx, va_list va);
int	ft_get_arg_X(t_ctx *ctx, va_list va);
int	ft_get_arg_o(t_ctx *ctx, va_list va);
int	ft_get_arg_b(t_ctx *ctx, va_list va);
int	ft_get_arg_prct(t_ctx *ctx, va_list va __attribute__((unused)));

static const t_cvrt	g_cvrt[] = {
	{'c', true, ft_get_arg_c},
	{'s', true, ft_get_arg_s},
	{'p', true, ft_get_arg_p},
	{'d', true, ft_get_arg_d_i},
	{'i', true, ft_get_arg_d_i},
	{'u', true, ft_get_arg_u},
	{'x', true, ft_get_arg_x},
	{'X', true, ft_get_arg_X},
	{'%', false, ft_get_arg_prct},
	{0}
};

#endif

