/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:45:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/04 03:32:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_cv	*ft_cv_add_back(t_cv *cv, char const elem)
{
	t_cv	*p;

	if (!cv)
		return (ft_cv_new(elem));
	else
	{
		p = cv;
		while (p->next)
			p = p->next;
		p->next = malloc(sizeof(t_cv));
		if (!p->next)
		{
			ft_cv_free(cv);
			return (NULL);
		}
		p->next->elem = elem;
	}
	return (cv);
}
