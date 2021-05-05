/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvrt_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:51:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 02:42:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_cvrt_print(t_cvrt *cv)
{
	while (cv)
	{
		ft_putchar_fd(cv->elem, 1);
		cv = cv->next;
	}
	ft_putchar_fd('\n', 1);
}
