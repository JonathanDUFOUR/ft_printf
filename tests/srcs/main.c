/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:31:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/19 00:36:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

#define TEST "|%#+*.*x|\n", -30, 20, 2147483647

int	main(void)
{
	int	ret;
	int	ft_ret;

	ret = printf(TEST);
	fflush(stdout);
	ft_ret = ft_printf(TEST);
	printf("ft_ret -> %d\n", ft_ret);
	fflush(stdout);
	printf("   ret -> %d\n", ret);
	fflush(stdout);
	return (SUCCESS);
}
