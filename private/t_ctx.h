/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:15:00 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:40:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

# include <stdbool.h>
# include <stdint.h>
# include "t_int.h"

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	int			len;
	uint16_t	flags;
	int			fwidth;
	int			prec;
	bool		precised;
};

#endif
