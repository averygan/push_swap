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
BONUS	= checker
SRCS	= pushswap/push_swap.c stack/stack_init.c stack/stack.c stack/pr_commands.c stack/rr_commands.c stack/swap_commands.c \
			pushswap/push_swap_utils.c pushswap/sort_algorithm.c pushswap/sort_helper.c pushswap/free.c pushswap/n_algorithm.c
BSRC	= bonus/checker_bonus.c bonus/stack_init_bonus.c bonus/stack_bonus.c bonus/swap_bonus.c bonus/pr_bonus.c bonus/rr_bonus.c \
			bonus/free_bonus.c bonus/checker_utils_bonus.c
OBJS 	= ${SRCS:.c=.o}
OBJS_BONUS	= ${BSRC:.c=.o}
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
LIBFT_BUILD := ./libft/libft.a

all: ${NAME}

${NAME} : ${OBJS} ${LIBFT_BUILD}
	@$(CC) ${CFLAGS} ${OBJS} -Llibft -lft -o ${NAME}
	@echo "push_swap compiled!"

${BONUS} : ${OBJS_BONUS} ${LIBFT_BUILD}
	@$(CC) ${CFLAGS} ${OBJS_BONUS} -Llibft -lft -o ${BONUS}
	@echo "checker compiled!"

.c.o:
	@$(CC) ${CFLAGS} -c $< -o $@

${LIBFT_BUILD}:
	@make -s -C ./libft

clean:
	@make -s clean -C ./libft
	@rm -f ${OBJS}
	@rm -f ${OBJS_BONUS}

fclean: clean
	@make -s fclean -C ./libft
	@rm -f ${NAME}
	@rm -f ${BONUS}
	@echo "fclean Completed!"

re: fclean all

bonus:	${BONUS}

.PHONY: all clean fclean re bonus

