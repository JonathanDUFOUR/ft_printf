/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:31:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/17 21:18:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

#define TEST "|%*.*b|\n", 15, 0, 0

int	main(void)
{
	int	ft_ret;
	int	ret;

	ft_ret = ft_printf(TEST);
	ret = printf(TEST);
	printf("ft_ret -> %d\n", ft_ret);
	printf("   ret -> %d\n", ret);
	return (SUCCESS);
}
