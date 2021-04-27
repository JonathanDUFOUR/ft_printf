# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:04:16 by jodufour          #+#    #+#              #
#    Updated: 2021/04/28 01:31:17 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
INCLUDE	=	includes
SRCD	=	srcs/
OBJD	=	objs/
CC		=	gcc -c -o
LINKER	=	ar rcs
MAKEDIR	=	mkdir -p
RM		=	rm -rf

SRCS	=	\
			main.c

OBJS	=	${SRCS:.c=.o}
OBJS	:=	${addprefix ${OBJD}, ${OBJS}}

DEPS	=	${OBJS:.o=.d}

CFLAGS	=	-Wextra -Wall -MMD -I ${INCLUDE}
LDFLAGS	=	-lftprintf

${NAME}:	${OBJS}
	${LINKER} $@ ${LDFLAGS} $^

all:	${NAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.c
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME}

re:	fclean all

.PHONY:	all, clean, fclean, re
