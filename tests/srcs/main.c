/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:31:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 03:17:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	ret;

	ret = ft_printf("%cspdiuxXc%spdiuxXcs%pdiuxXcsp%diuxXcspd%iuxXcspdi%uxXcspdiu%xXcspdiux%XcspdiuxX%%\n");
	printf("ret == %d\n", ret);
	return (SUCCESS);
}
