/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:29:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 03:17:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	ft_queue_free(t_queue *queue)
{
	t_queue	*dent;

	while (queue)
	{
		dent = queue;
		queue = queue->next;
		free(dent);
	}
}
