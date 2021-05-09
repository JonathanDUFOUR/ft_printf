/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/09 04:42:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>

# define FLAG_CHARS		"#0- +'I"
# define PRECI_CHARS	"."
# define LEN_MODIF		"hlqL"
# define CONVERT_SPEC	"cspdiuxX%"

enum	e_ret
{
	MALLOC_ERRNO = -1,
	SUCCESS
};

int			ft_printf(const char *format, ...);
char const	*ft_manage_arg(char const *format, char **to_print, va_list va);
char const	*ft_manage_spec(char const *format, char **to_print, va_list va);
void		ft_get_arg_c(char **to_print, va_list va);
void		ft_get_arg_s(char **to_print, va_list va);
void		ft_get_arg_p(char **to_print, va_list va);
void		ft_get_arg_d_i(char **to_print, va_list va);
void		ft_get_arg_u(char **to_print, va_list va);
void		ft_get_arg_x(char **to_print, va_list va);
void		ft_get_arg_X(char **to_print, va_list va);

#endif
