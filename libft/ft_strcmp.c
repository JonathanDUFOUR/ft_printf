/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:26:33 by jdufour           #+#    #+#             */
/*   Updated: 2021/04/06 19:58:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char const *s1, char const *s2)
{
	while (s1 && s2 && *s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
