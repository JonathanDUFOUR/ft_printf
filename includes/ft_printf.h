/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/14 02:01:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdint.h>
# include <stdarg.h>

/* Remove it when finished */
# include <stdio.h>

# define FLAG_CHARS		"-0"
# define PRECI_CHAR		"."
# define LEN_MODIF		"hlqL"
# define CONVERT_SPEC	"cspdiuxX%"

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	char	*print;
	uint8_t	flags;
	char	padding;
	int		field_width;
	int		precision;
};

enum	e_ret
{
	MALLOC_ERRNO = -1,
	SUCCESS
};

int			ft_printf(char const *format, ...);
char const	*ft_manage_arg(char const *format, t_ctx *ctx, va_list va);
char const	*ft_manage_flags(char const *format, t_ctx *ctx);
char const	*ft_manage_field_width(char const *format, t_ctx *ctx, va_list va);
char const	*ft_manage_precision(char const *format, t_ctx *ctx, va_list va);
char const	*ft_manage_specifier(char const *format, t_ctx *ctx, va_list va);
char const	*ft_manage_text(char const *format, t_ctx *ctx);
char		*ft_get_arg_c(t_ctx *ctx, va_list va);
char		*ft_get_arg_d_i(t_ctx *ctx, va_list va);
char		*ft_get_arg_p(t_ctx *ctx, va_list va);
char		*ft_get_arg_prct(t_ctx *ctx);
char		*ft_get_arg_s(t_ctx *ctx, va_list va);
char		*ft_get_arg_u(t_ctx *ctx, va_list va);
char		*ft_get_arg_x(t_ctx *ctx, va_list va);
char		*ft_get_arg_X(t_ctx *ctx, va_list va);
char		*ft_get_text(char const *format, char *print);

#endif
