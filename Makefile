# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 19:17:06 by aurodrig          #+#    #+#              #
#    Updated: 2024/08/11 19:57:13 by aurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker

CC = cc

CFLAGS = -O3 -Wall -Wextra -Werror -fsanitize=address -g

SRCS = main.c \
	   Utils/ft_atoi.c \
	   Utils/ft_split.c \
	   Utils/ft_isdigit.c \
	   Utils/ft_strlen.c \
	   Utils/lists_aux.c \
	   Utils/lists_aux2.c \
	   src/Operations/swap.c \
	   src/Operations/push.c \
	   src/Operations/reverse_rotate.c \
	   src/Operations/rotate.c \
	   src/parsing.c \
	   src/cost_algorithm.c \
	   src/cost_aux_functions.c \
	   src/load_list.c \
	   src/put_top.c \
	   src/smaller_sort.c \
	   src/print_moves.c \
	   src/get_best_pair.c 

CHECKER_SRCS = bonus/checker.c \
			   bonus/checker_utils.c \
			   Utils/ft_atoi.c \
			   Utils/ft_split.c \
			   Utils/ft_isdigit.c \
			   Utils//ft_strlen.c \
			   Utils/lists_aux.c \
			   Get_Next_Line/get_next_line.c \
			   Get_Next_Line/get_next_line_utils.c \
			   src/Operations/swap.c \
			   src/Operations/push.c \
			   src/Operations/reverse_rotate.c \
			   src/Operations/rotate.c \
			   src/print_moves.c \
	  		   src/parsing.c \
			   src/load_list.c 

OBJS	= ${SRCS:.c=.o}
CHECKER_OBJS = ${CHECKER_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

${CHECKER_NAME}: ${CHECKER_OBJS}
		${CC} ${CFLAGS} ${CHECKER_OBJS} -o ${CHECKER_NAME}

clean:
	rm -f ${OBJS}

clean_checker:
	rm -f $(CHECKER_OBJS)

fclean: clean
	rm -f ${NAME}

fclean_checker: clean_checker
		@rm -rf ${CHECKER_NAME}

fclean_all: clean fclean_checker

re: fclean all

re_checker: fclean_checker checker

.PHONY: all clean fclean re