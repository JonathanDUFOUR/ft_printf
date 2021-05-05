/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:51:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 03:29:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_queue_print(t_queue *queue)
{
	while (queue)
	{
		ft_putchar_fd(queue->type, 1);
		queue = queue->next;
	}
	ft_putchar_fd('\n', 1);
}
