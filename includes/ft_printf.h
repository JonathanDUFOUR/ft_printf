/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/05 22:02:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>

# define FLAG_CHARS		"#0- +'I"
# define FIELD_WIDTH	"0123456789"
# define PRECI_CHARS	"."
# define LENGTH_MODIF	"hlqL"
# define CONVERT_SPEC	"cspdiuxX%"

enum	e_ret
{
	ERROR = -3,
	CV_ERRNO = -2,
	MALLOC_ERRNO = -1,
	SUCCESS = 0
};

int		ft_printf(const char *format, ...);
ssize_t	ft_va_count(char const *format);

#endif
