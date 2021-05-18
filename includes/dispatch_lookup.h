/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_lookup.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 04:09:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 06:19:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_LOOKUP_H
# define DISPATCH_LOOKUP_H

# include "t_cvrt.h"

int	get_arg_c_lower(t_ctx *ctx, va_list va);
int	get_arg_s_lower(t_ctx *ctx, va_list va);
int	get_arg_p_lower(t_ctx *ctx, va_list va);
int	get_arg_d_lower(t_ctx *ctx, va_list va);
int	get_arg_u_lower(t_ctx *ctx, va_list va);
int	get_arg_x_lower(t_ctx *ctx, va_list va);
int	get_arg_x_upper(t_ctx *ctx, va_list va);
int	get_arg_o_lower(t_ctx *ctx, va_list va);
int	get_arg_b_lower(t_ctx *ctx, va_list va);
int	get_arg_prct(t_ctx *ctx, va_list va __attribute__((unused)));

static const t_cvrt	g_cvrt[] = {
	{'c', true, get_arg_c_lower},
	{'s', true, get_arg_s_lower},
	{'p', true, get_arg_p_lower},
	{'d', true, get_arg_d_lower},
	{'i', true, get_arg_d_lower},
	{'u', true, get_arg_u_lower},
	{'x', true, get_arg_x_lower},
	{'X', true, get_arg_x_upper},
	{'o', true, get_arg_o_lower},
	{'b', true, get_arg_b_lower},
	{'%', false, get_arg_prct},
	{0}
};

#endif
