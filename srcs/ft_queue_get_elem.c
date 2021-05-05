/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_get_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 03:44:58 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 03:59:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	ft_queue_get_elem(t_queue *queue, va_list *va)
{
	if (queue->type == 'c')
		queue->elem = va_arg(*va, char);
	else if (queue->type == 's')
		queue->elem = va_arg(*va, char *);
	else if (queue->type == 'p')
		queue->elem = va_arg(*va, void *);
	else if (queue->type == 'd' || queue->type == 'i')
		queue->elem = va_arg(*va, int);
	else if (queue->type == 'u' || queue->type == 'x' || queue->type == 'X')
		queue->elem = va_arg(*va, unsigned int);
}
