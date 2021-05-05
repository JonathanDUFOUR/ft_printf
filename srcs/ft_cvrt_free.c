/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvrt_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:29:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 02:42:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	ft_cvrt_free(t_cvrt *cv)
{
	t_cvrt	*dent;

	while (cv)
	{
		dent = cv;
		cv = cv->next;
		free(dent);
	}
}
