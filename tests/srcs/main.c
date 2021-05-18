/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:31:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:30:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

#define TEST "|%#*.*X|\n", -30, 20, 2147483647

int	main(void)
{
	int	ret;
	int	ret;

	ret = ft_printf(TEST);
	ret = ft_printf(TEST);
	fflush(stdout);
	ft_printf("ret -> %d\n", ret);
	fflush(stdout);
	ft_printf("   ret -> %d\n", ret);
	return (SUCCESS);
}
