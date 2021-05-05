/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 02:40:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdbool.h>

# define CV_CHARS	"cspdiuxX%"

enum	e_ret
{
	ERROR = -1,
	SUCCESS,
	CV_ERRNO,
	MALLOC_ERRNO
};

typedef struct s_cvrt	t_cvrt;

struct					s_cvrt
{
	char	elem;
	t_cvrt	*next;
};

int		ft_printf(const char *format, ...);
int		ft_multifree(int ret, uint32_t n, ...);
bool	ft_cvrt_is_valid(char const c);
void	ft_cvrt_print(t_cvrt *cv);
void	ft_cvrt_free(t_cvrt *cv);
t_cvrt	*ft_cvrt_add_back(t_cvrt *cv, char const elem);
t_cvrt	*ft_cvrt_new(char const elem);

#endif
