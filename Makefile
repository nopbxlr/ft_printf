# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctherin <ctherin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 18:24:45 by ctherin           #+#    #+#              #
#    Updated: 2022/06/20 18:26:14 by ctherin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_mem_utils.c \
ft_itoa_base.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar -vcrs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
