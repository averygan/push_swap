# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 12:22:42 by agan              #+#    #+#              #
#    Updated: 2023/10/30 12:22:43 by agan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
SRCS	= push_swap.c stack.c instructions.c push_swap_utils.c stack_parser.c
OBJS 	= ${SRCS:.c=.o}
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g
LIBFT_BUILD := ./libft/libft.a

all: ${NAME}

${NAME} : ${OBJS} ${LIBFT_BUILD}
	@$(CC) ${CFLAGS} ${OBJS} -Llibft -lft -o ${NAME}
	@echo "push_swap compiled!"

.c.o:
	@$(CC) ${CFLAGS} -c $< -o $@

${LIBFT_BUILD}:
	@make -s -C ./libft

clean:
	@make -s clean -C ./libft
	@rm -f ${OBJS}

fclean: clean
	@make -s fclean -C ./libft
	@rm -f ${NAME}
	@echo "fclean Completed!"

re: fclean all

.PHONY: all clean fclean re

