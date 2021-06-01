/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/02 00:40:43 by jodufour         ###   ########.fr       */
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

/*
**	(1 << 0) -> '-'
**	(1 << 1) -> '0'
**	(1 << 2) -> '+'
**	(1 << 3) -> ' '
**	(1 << 4) -> '#'
**
**	(1 << 5) -> l
**	(1 << 6) -> ll
**	(1 << 7) -> h
**	(1 << 8) -> hh
*/
# define FLAG_CHARS		"-0+ #"
# define LEN_MODIF		"hlqL"
# define CONVERT_SPEC	"cspdiuxX%"

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	uint32_t	len;
	uint16_t	flags;
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
char const	*manage_arg(char const *format, t_ctx *ctx, va_list va);
char const	*manage_flags(char const *format, t_ctx *ctx);
char const	*manage_field_width(char const *format, t_ctx *ctx, va_list va);
char const	*manage_precision(char const *format, t_ctx *ctx, va_list va);
char const	*manage_length_modifier(char const *format, t_ctx *ctx);
char const	*manage_specifier(char const *format, t_ctx *ctx, va_list va);
char const	*manage_text(char const *format, t_ctx *ctx);
int			padding(int c, uint32_t padlen);
uint32_t	dlen(long long int n);
uint32_t	ulen(unsigned long long int n);
uint32_t	plen(uint64_t n);
uint32_t	xlen(uint32_t n);
uint32_t	olen(uint32_t n);
uint32_t	blen(uint32_t n);

#endif
