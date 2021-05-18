/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 04:35:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>

/* Remove it when finished */
# include <stdio.h>

# define FLAG_CHARS		"-0+ #"
# define LEN_MODIF		"hlqL"
# define CONVERT_SPEC	"cspdiuxX%"

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	uint32_t	len;
	uint8_t		flags;
	uint32_t	fwidth;
	uint32_t	prec;
	bool		precised;
};

enum	e_padding_side
{
	LEFT,
	RIGHT,
	NONE
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
int			ft_padding(int c, uint32_t padlen);
uint32_t	ft_plen(uint64_t n);
uint32_t	ft_xlen(uint32_t n);
uint32_t	ft_olen(uint32_t n);
uint32_t	ft_blen(uint32_t n);

#endif
