/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:31:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/14 03:20:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	ft_ret;
	int	ret;

	ret = printf("%*c|\n", -3, 'A');
	ft_ret = ft_printf("%*c|\n", -3, 'A');
	printf("ft_ret -> %d\n", ft_ret);
	printf("   ret -> %d\n", ret);
	return (SUCCESS);
}
