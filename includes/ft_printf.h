/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/04 04:02:07 by jodufour         ###   ########.fr       */
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

typedef struct s_cv	t_cv;

struct					s_cv
{
	char	elem;
	t_cv	*next;
};

int		ft_printf(const char *format, ...);
int		ft_multifree(int ret, uint32_t n, ...);
int		ft_cv_get(t_cv **cv, char const *format);
bool	ft_cv_is_valid(char const c);
void	ft_cv_print(t_cv *cv);
void	ft_cv_free(t_cv *cv);
t_cv	*ft_cv_add_back(t_cv *cv, char const elem);
t_cv	*ft_cv_new(char const elem);

#endif
