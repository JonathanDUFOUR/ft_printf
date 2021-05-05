/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 03:17:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdbool.h>

# define CV_CHARS	"cspdiuxX%"

enum	e_ret
{
	ERROR = -3,
	CV_ERRNO = -2,
	MALLOC_ERRNO = -1,
	SUCCESS = 0
};

typedef struct s_queue	t_queue;

struct					s_queue
{
	char	elem;
	t_queue	*next;
};

int		ft_printf(const char *format, ...);
int		ft_multifree(int ret, uint32_t n, ...);
int		ft_queue_get(t_queue **cvrt, char const *format);
void	ft_queue_print(t_queue *cv);
void	ft_queue_free(t_queue *cv);
t_queue	*ft_queue_add_back(t_queue *cv, char const elem);
t_queue	*ft_queue_new(char const elem);

#endif
