/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:29:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/04 03:31:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	ft_cv_free(t_cv *cv)
{
	t_cv	*dent;

	while (cv)
	{
		dent = cv;
		cv = cv->next;
		free(dent);
	}
}
