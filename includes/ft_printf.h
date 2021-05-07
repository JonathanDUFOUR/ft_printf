/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/07 04:45:52 by jodufour         ###   ########.fr       */
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

typedef union u_unival	t_unival;

union					u_unival
{
	float		f;
	uint32_t	n;
	void		*p;
};

enum	e_ret
{
	STYLE_ERRNO = -2,
	MALLOC_ERRNO,
	SUCCESS,
	SIMPLE_STYLE,
	DOLLAR_STYLE
};

enum	e_counts
{
	POURCENT,
	DOLLAR,
	STAR
};

int		ft_printf(const char *format, ...);
int		ft_check_style(char const *format);
size_t	ft_va_count(char const *format);

#endif
