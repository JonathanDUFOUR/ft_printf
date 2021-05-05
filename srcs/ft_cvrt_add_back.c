/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvrt_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:45:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 02:42:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_cvrt	*ft_cvrt_add_back(t_cvrt *cv, char const elem)
{
	t_cvrt	*p;

	if (!cv)
		return (ft_cvrt_new(elem));
	else
	{
		p = cv;
		while (p->next)
			p = p->next;
		p->next = malloc(sizeof(t_cvrt));
		if (!p->next)
		{
			ft_cvrt_free(cv);
			return (NULL);
		}
		p->next->elem = elem;
	}
	return (cv);
}
