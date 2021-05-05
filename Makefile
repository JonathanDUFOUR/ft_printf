# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:04:16 by jodufour          #+#    #+#              #
#    Updated: 2021/05/05 03:44:37 by jodufour         ###   ########.fr        #
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
			ft_strlen.c		\
			ft_strchr.c		\
			ft_putstr_fd.c	\
			ft_putnbr_fd.c	\
			ft_putchar_fd.c	\

FT_SRCS	:=	${addprefix ${LIBFTD}, ${FT_SRCS}}

SRCS	=	\
			${FT_SRCS}			\
			ft_printf.c			\
			ft_queue_new.c		\
			ft_queue_free.c		\
			ft_queue_print.c	\
			ft_queue_get_type.c	\
			ft_queue_get_elem.c	\
			ft_queue_add_back.c	\

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
