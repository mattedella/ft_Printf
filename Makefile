# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 22:16:14 by mdella-r          #+#    #+#              #
#    Updated: 2023/11/13 10:33:57 by mdella-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MANDATORY_SRCS = ft_printf.c ft_convert_base_up.c ft_convert_base_low.c ft_itoa.c ft_itoa_un.c ft_putstr.c ft_putchar.c ft_adr_base.c 
MANDATORY_OBJS = ${MANDATORY_SRCS:.c=.o}
HEADER = ft_printf.h

all: ${NAME}

${NAME}: ${MANDATORY_OBJS}
	ar rc ${NAME} ${MANDATORY_OBJS}
	ranlib ${NAME}

%.o: %.c ${HEADER}
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f ${MANDATORY_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus