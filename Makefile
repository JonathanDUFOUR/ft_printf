# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:04:16 by jodufour          #+#    #+#              #
#    Updated: 2021/05/09 06:39:37 by jodufour         ###   ########.fr        #
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
			ft_bzero.c		\
			ft_calloc.c		\
			ft_ctoa.c		\
			ft_int_size.c	\
			ft_itoa.c		\
			ft_memcpy.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_strjoin.c	\
			ft_strlen.c		\
			ft_strndup.c	\
			ft_uint_size.c	\
			ft_utoa.c		\

FT_SRCS	:=	${addprefix ${LIBFTD}, ${FT_SRCS}}

SRCS	=	\
			${FT_SRCS}			\
			ft_printf.c			\
			ft_get_text.c		\
			ft_get_arg_c.c		\
			ft_get_arg_s.c		\
			ft_get_arg_p.c		\
			ft_get_arg_d_i.c	\
			ft_get_arg_u.c		\
			ft_get_arg_x.c		\
			ft_get_arg_X.c		\
			ft_manage_arg.c		\
			ft_manage_spec.c	\
			ft_manage_text.c

OBJS	=	${SRCS:.c=.o}
OBJS	:=	${addprefix ${OBJD}, ${OBJS}}

DEPS		=	${OBJS:.o=.d}

CFLAGS		=	-Wextra -Wall -MMD -I ${INCLUDE}
LDFLAGS		=

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
