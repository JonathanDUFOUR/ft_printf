/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:31:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 03:30:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

#define TEST "|%#*.*X|\n", -30, 20, 2147483647

int	main(void)
{
	int	ft_ret;
	int	ret;

	ft_ret = ft_printf(TEST);
	ret = printf(TEST);
	fflush(stdout);
	printf("ft_ret -> %d\n", ft_ret);
	fflush(stdout);
	printf("   ret -> %d\n", ret);
	return (SUCCESS);
}
