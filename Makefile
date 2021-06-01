# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:04:16 by jodufour          #+#    #+#              #
#    Updated: 2021/06/02 00:19:34 by jodufour         ###   ########.fr        #
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
			c/get_arg_c_lower.c			\
			s/get_arg_s_lower.c			\
			p/get_arg_p_lower.c			\
			d/get_arg_d_lower.c			\
			u/get_arg_u_lower.c			\
			x/get_arg_x_lower.c			\
			x/get_arg_x_upper.c			\
			o/get_arg_o_lower.c			\
			b/get_arg_b_lower.c			\
			%/get_arg_prct.c			\
			manage_arg.c				\
			manage_flags.c				\
			manage_field_width.c		\
			manage_precision.c			\
			manage_length_modifier.c	\
			manage_specifier.c			\
			manage_text.c				\
			padding.c					\
			p/plen.c					\
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
