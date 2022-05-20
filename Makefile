# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 15:02:31 by jodufour          #+#    #+#              #
#    Updated: 2022/05/19 02:56:23 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC		=	clang
LINK	=	ar rcs
MKDIR	=	mkdir -p
RM		=	rm -rf

#######################################
#              LIBRARIES              #
#######################################
NAME	=	libftprintf.a

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR	=	srcs/
OBJ_DIR	=	objs/
INC_DIR	=	include/
PRV_DIR	=	private/

######################################
#            SOURCE FILES            #
######################################
SRC		=	\
			${addprefix cvrt/,		\
				cvrt_b.c			\
				cvrt_c.c			\
				cvrt_d.c			\
				cvrt_o.c			\
				cvrt_p.c			\
				cvrt_prct.c			\
				cvrt_s.c			\
				cvrt_u.c			\
				cvrt_x.c			\
				putnil.c			\
				putnull.c			\
			}						\
			${addprefix utils/,		\
				ft_atoi.c			\
				ft_isdigit.c		\
				ft_isspace.c		\
				ft_llintlen.c		\
				ft_lluintlen_bin.c	\
				ft_lluintlen_hexa.c	\
				ft_lluintlen_oct.c	\
				ft_lluintlen.c		\
				ft_putchar.c		\
				ft_putllint.c		\
				ft_putlluint_bin.c	\
				ft_putlluint_hexa.c	\
				ft_putlluint_oct.c	\
				ft_putlluint.c		\
				ft_putwchar.c		\
				ft_strchr.c			\
				ft_strlen.c			\
				ft_wclen.c			\
				ft_wstrlen.c		\
				ft_wstrsize.c		\
			}						\
			ft_printf.c				\
			manage_cvrt.c			\
			manage_text.c			\
			padding.c				\
			parse_flags.c			\
			parse_fwidth.c			\
			parse_lmod.c			\
			parse_prec.c

######################################
#            OBJECT FILES            #
######################################
OBJ		=	${SRC:.c=.o}
OBJ		:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP		=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS	=	-c
CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-I${INC_DIR}
CFLAGS	+=	-I${PRV_DIR}

LDFLAGS	=	

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
.PHONY: all bonus clean fclean re fre

${NAME}: ${OBJ}
	${LINK} $@ $^ ${LDFLAGS}

all: ${NAME}

bonus: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $< ${CFLAGS} ${OUTPUT_OPTION}

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}

re: clean all

fre: fclean all

-include ${HOME}/Templates/mk_files/coffee.mk
-include ${HOME}/Templates/mk_files/norm.mk
