/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:23:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/04 03:25:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_cv	*ft_cv_new(char const elem)
{
	t_cv	*output;

	output = malloc(sizeof(t_cv));
	if (!output)
		return (NULL);
	output->elem = elem;
	output->next = NULL;
	return (output);
}
