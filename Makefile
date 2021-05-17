# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:04:16 by jodufour          #+#    #+#              #
#    Updated: 2021/05/17 21:15:29 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
INCLUDE	=	includes
SRCD	=	srcs/
OBJD	=	objs/
LIBFTD	=	libft/
CC		=	gcc -c -o
LINKER	=	ar rcs
MAKEDIR	=	mkdir -p
RM		=	rm -rf

FT_SRCS	=	\
			ft_atou.c		\
			ft_intlen.c		\
			ft_isdigit.c	\
			ft_isspace.c	\
			ft_putchar.c	\
			ft_putnbr.c		\
			ft_putunbr.c	\
			ft_strchr.c		\
			ft_strlen.c		\
			ft_uintlen.c	\

FT_SRCS	:=	${addprefix ${LIBFTD}, ${FT_SRCS}}

SRCS	=	\
			${FT_SRCS}				\
			ft_printf.c				\
			ft_get_arg_c.c			\
			ft_get_arg_s.c			\
			ft_get_arg_p.c			\
			ft_get_arg_d_i.c		\
			ft_get_arg_u.c			\
			ft_get_arg_x.c			\
			ft_get_arg_X.c			\
			ft_get_arg_o.c			\
			ft_get_arg_b.c			\
			ft_get_arg_prct.c		\
			ft_manage_arg.c			\
			ft_manage_flags.c		\
			ft_manage_field_width.c	\
			ft_manage_precision.c	\
			ft_manage_specifier.c	\
			ft_manage_text.c		\
			ft_padding.c			\
			ft_plen.c				\
			ft_xlen.c				\
			ft_olen.c				\
			ft_blen.c

OBJS	=	${SRCS:.c=.o}
OBJS	:=	${addprefix ${OBJD}, ${OBJS}}

DEPS		=	${OBJS:.o=.d}

CFLAGS		=	-Wextra -Wall -MMD -I ${INCLUDE}
LDFLAGS		=

ifeq (${DEBUG}, true)
	CFLAGS	+=	-g
endif

${NAME}:	${OBJS}
	${LINKER} $@ ${LDFLAGS} ${OBJS}

all:	${NAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.c
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

${OBJD}${LIBFTD}%.o:	${LIBFTD}%.c
	@${MAKEDIR} ${OBJD}
	@${MAKEDIR} ${OBJD}${LIBFTD}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
