/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:31:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/20 21:25:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

#define TEST "|%0+*.*d|\n", 22, -1, 6234

int	main(void)
{
	int	ret;
	int	ft_ret;

	ft_ret = ft_printf(TEST);
	ret = printf(TEST);
	fflush(stdout);
	printf("ft_ret -> %d\n", ft_ret);
	fflush(stdout);
	printf("   ret -> %d\n", ret);
	fflush(stdout);
	return (SUCCESS);
}
