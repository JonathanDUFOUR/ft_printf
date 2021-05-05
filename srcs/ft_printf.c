/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:58:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 02:41:24 by jodufour         ###   ########.fr       */
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
	t_cvrt	*cvrt;
	va_list	va;

	cvrt = NULL;
	ret = ft_cvrt_get(&cvrt, format);
	if (ret != SUCCESS)
		return (ret);
	ft_cvrt_print(cvrt);
	return (42);
}
