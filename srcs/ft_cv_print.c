/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:51:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/04 04:03:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_cv_print(t_cv *cv)
{
	while (cv)
	{
		ft_putchar_fd(cv->elem, 1);
		cv = cv->next;
	}
	ft_putchar_fd('\n', 1);
}
