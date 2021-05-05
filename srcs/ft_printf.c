/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:58:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 03:17:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_queue	*queue;
	va_list	va;

	queue = NULL;
	ret = ft_queue_get(&queue, format);
	if (ret < 0)
		return (ret);
	ft_putnbr_fd(ret, 1);
	ft_putchar_fd('\n', 1);
	va_start(va, format);
	va_end(va);
	ft_queue_print(queue);
	return (42);
}
