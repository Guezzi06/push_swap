# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 15:59:53 by aguezzi           #+#    #+#              #
#    Updated: 2023/04/13 13:38:40 by aguezzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= push_swap.c create_list.c less_five_numbers.c all_other_numbers.c optimisation_1.c optimisation_2.c calculs_tmp_1.c calculs_tmp_2.c ex_instructions_1.c ex_instructions_2.c sort_b.c split_numbers.c check_error.c

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

all:	${NAME}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C libft
		${CC} -g ${FLAGS} -Llibft -lft ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}
		make clean -C libft

fclean:	clean
		${RM} ${NAME}
		${RM} libft/libft.a

re:	fclean all

.PHONY:	all clean fclean re