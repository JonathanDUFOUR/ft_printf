/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_lookup.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 04:09:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/02 01:18:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_LOOKUP_H
# define DISPATCH_LOOKUP_H

# include "t_cvrt.h"

int	get_arg_c(t_ctx *ctx, va_list va);
int	get_arg_s(t_ctx *ctx, va_list va);
int	get_arg_p(t_ctx *ctx, va_list va);
int	d_dispatch(t_ctx *ctx, va_list va);
int	get_arg_u(t_ctx *ctx, va_list va);
int	get_arg_x_lower(t_ctx *ctx, va_list va);
int	get_arg_x_upper(t_ctx *ctx, va_list va);
int	get_arg_o(t_ctx *ctx, va_list va);
int	get_arg_b(t_ctx *ctx, va_list va);
int	get_arg_prct(t_ctx *ctx, va_list va __attribute__((unused)));

static const t_cvrt	g_cvrt[] = {
	{'c', true, get_arg_c},
	{'s', true, get_arg_s},
	{'p', true, get_arg_p},
	{'d', true, d_dispatch},
	{'i', true, d_dispatch},
	{'u', true, get_arg_u},
	{'x', true, get_arg_x_lower},
	{'X', true, get_arg_x_upper},
	{'o', true, get_arg_o},
	{'b', true, get_arg_b},
	{'%', false, get_arg_prct},
	{0}
};

#endif
