/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cvrt_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:23:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 02:42:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_cvrt	*ft_cvrt_new(char const elem)
{
	t_cvrt	*output;

	output = malloc(sizeof(t_cvrt));
	if (!output)
		return (NULL);
	output->elem = elem;
	output->next = NULL;
	return (output);
}
