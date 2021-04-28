# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 02:13:29 by jodufour          #+#    #+#              #
#    Updated: 2021/04/28 02:34:05 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	tests
LIBPATH	=	../libftprintf.a
INCLUDE	=	../includes
SRCD	=	srcs/
OBJD	=	objs/
CC		=	gcc -c -o
LINKER	=	gcc -o
MAKEDIR	=	mkdir -p
RM		=	rm -rf

SRCS	=	\
			main.c

OBJS	=	${SRCS:.c=.o}
OBJS	:=	${addprefix ${OBJD}, ${OBJS}}

DEPS	=	${OBJS:.o=.d}

CFLAGS	=	-Wall -Wextra -I ${INCLUDE} -MMD
LDFLAGS	=	

${NAME}:	${OBJS} 
	${LINKER} $@ ${LDFLAGS} $^ ${LIBPATH}

all:	${NAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.c
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
