# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:04:16 by jodufour          #+#    #+#              #
#    Updated: 2021/06/02 01:38:55 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
INCLUDE	=	includes
SRCD	=	srcs/
OBJD	=	objs/
LIBFTD	=	libft/
FT_SRCD	=	srcs/

CC		=	gcc -c -o
LINKER	=	ar rcs
MAKEDIR	=	mkdir -p
RM		=	rm -rf

FT_SRCS	=	\
			ft_atou.c			\
			ft_intlen.c			\
			ft_isdigit.c		\
			ft_isspace.c		\
			ft_putbytes.c		\
			ft_putchar.c		\
			ft_putnbr.c			\
			ft_putnbr_bin.c		\
			ft_putnbr_hexa.c	\
			ft_putnbr_oct.c		\
			ft_putstr.c			\
			ft_putunbr.c		\
			ft_strchr.c			\
			ft_strlen.c			\
			ft_uintlen.c		\

FT_SRCS	:=	${addprefix ${LIBFTD}, ${FT_SRCS}}

SPECD	=	\
			%/	\
			b/	\
			c/	\
			d/	\
			o/	\
			p/	\
			s/	\
			u/	\
			x/

SPECD	:=	${addprefix ${OBJD}, ${SPECD}}

SRCS	=	\
			${FT_SRCS}					\
			ft_printf.c					\
			manage_arg.c				\
			manage_flags.c				\
			manage_field_width.c		\
			manage_precision.c			\
			manage_length_modifier.c	\
			manage_specifier.c			\
			manage_text.c				\
			padding.c					\
			c/get_arg_c.c				\
			s/get_arg_s.c				\
			p/plen.c					\
			p/get_arg_p.c				\
			u/ulen.c					\
			u/get_arg_u.c				\
			x/get_arg_x_lower.c			\
			x/get_arg_x_upper.c			\
			o/get_arg_o.c				\
			b/get_arg_b.c				\
			%/get_arg_prct.c			\
			d/dlen.c					\
			d/d_dispatch.c				\
			d/get_arg_d.c				\
			d/get_arg_hd.c				\
			d/get_arg_hhd.c				\
			d/get_arg_ld.c				\
			d/get_arg_lld.c				\
			d/putllnbr.c				\
			d/padded_putnbr.c			\
			x/xlen.c					\
			o/olen.c					\
			b/blen.c

OBJS	=	${SRCS:.c=.o}
OBJS	:=	${addprefix ${OBJD}, ${OBJS}}

DEPS		=	${OBJS:.o=.d}

CFLAGS		=	-Wextra -Wall -Werror -MMD -I ${INCLUDE}
LDFLAGS		=

ifeq (${DEBUG}, true)
	CFLAGS	+=	-g
endif

${NAME}:	${OBJS}
	${LINKER} $@ ${LDFLAGS} ${OBJS}

all:	${NAME}

bonus:	${NAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.c
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

${OBJD}${LIBFTD}%.o:	${LIBFTD}${FT_SRCD}%.c
	@${MAKEDIR} ${OBJD}
	@${MAKEDIR} ${OBJD}${LIBFTD}
	@${MAKEDIR} ${SPECD}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME}

re:	fclean all

.PHONY:	all bonus clean fclean re
