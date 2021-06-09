/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:32:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/06 16:46:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>

/* Remove it when finished */
# include <stdio.h>

# define LU		unsigned long int
# define LLU	unsigned long long int
# define HU		unsigned short int
# define HHU	unsigned char

# define LD		long int
# define LLD	long long int
# define HD		short int
# define HHD	char

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

enum	e_style
{
	LOWER,
	UPPER
};

enum	e_ret
{
	WRITE_ERRNO = -2,
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
void		putllnbr(LLD n);
void		putllunbr(LLU n);
void		putllunbr_bin(LLU n);
void		putllunbr_oct(LLU n);
void		putllunbr_hexa(LLU n, char c);
uint32_t	dlen(LLD n);
uint32_t	ulen(LLU n);
uint32_t	plen(LU n);
uint32_t	xlen(LLU n);
uint32_t	olen(LLU n);
uint32_t	blen(LLU n);

#endif
