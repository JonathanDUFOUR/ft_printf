/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:45:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 03:17:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_queue	*ft_queue_add_back(t_queue *queue, char const elem)
{
	t_queue	*p;

	if (!queue)
		return (ft_queue_new(elem));
	else
	{
		p = queue;
		while (p->next)
			p = p->next;
		p->next = malloc(sizeof(t_queue));
		if (!p->next)
		{
			ft_queue_free(queue);
			return (NULL);
		}
		p->next->elem = elem;
	}
	return (queue);
}
