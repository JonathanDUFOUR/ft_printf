/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/10 21:50:19 by jodufour         ###   ########.fr       */
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

int			ft_printf(char const *format, ...);
char const	*ft_manage_arg(char const *format, char **print, va_list va);
char const	*ft_manage_spec(char const *format, char **print, va_list va);
char const	*ft_manage_text(char const *format, char **print);
char		*ft_get_arg_c(char *print, va_list va);
char		*ft_get_arg_d_i(char *print, va_list va);
char		*ft_get_arg_p(char *print, va_list va);
char		*ft_get_arg_prct(char *print);
char		*ft_get_arg_s(char *print, va_list va);
char		*ft_get_arg_u(char *print, va_list va);
char		*ft_get_arg_x(char *print, va_list va);
char		*ft_get_arg_X(char *print, va_list va);
char		*ft_get_text(char const *format, char *print);

#endif
