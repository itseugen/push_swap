# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 15:24:01 by eweiberl          #+#    #+#              #
#    Updated: 2023/05/03 15:27:51 by eweiberl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCE = push_swap.c

OBJS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(SOURCE)
	@cd libft && make
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCE) ./libft/libft.a

clean:
	@rm -f $(OBJS)
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re clean_obj
