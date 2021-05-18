/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cvrt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 04:11:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:30:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CVRT_H
# define T_CVRT_H

# include <stdarg.h>
# include <stdbool.h>
# include "ft_printf.h"

typedef struct s_cvrt	t_cvrt;

struct s_cvrt
{
	char	c;
	bool	need_arg;
	int		(*fct)(t_ctx *ctx, va_list va);
};

#endif
