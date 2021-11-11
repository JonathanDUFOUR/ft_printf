/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:54:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/11 17:06:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

#define TEST NULL

int	main(void)
{
	int	ret;
	int	ft_ret;

	printf("   printf[");
	ret = printf(TEST);
	printf("] = %d\n", ret);
	printf("ft_printf[");
	fflush(stdout);
	ft_ret = ft_printf(TEST);
	printf("] = %d\n", ft_ret);
	return (0);
}
