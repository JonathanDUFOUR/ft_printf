/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:31:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/14 04:37:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	ft_ret;
	int	ret;

	ret = printf("%.*d|\n", 8, -2147483647);
	ft_ret = ft_printf("%.*d|\n", 8, -2147483647);
	printf("ft_ret -> %d\n", ft_ret);
	printf("   ret -> %d\n", ret);
	return (SUCCESS);
}
