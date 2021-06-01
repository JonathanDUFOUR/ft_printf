/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:31:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/01 23:29:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

#define TEST "|%hd|\n", 6234

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
