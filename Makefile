# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 15:24:01 by eweiberl          #+#    #+#              #
#    Updated: 2023/05/12 18:39:35 by eweiberl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCE = push_swap.c check_input.c push_a_b.c testers.c stack_init.c helpers.c\
		onetilln.c listops.c rotate.c sorting.c stackops.c issorted.c

OBJS = $(SOURCE:.c=.o)

LIBFT_GIT	=	https://github.com/itseugen/c_library
LIBFT_DIR	=	./libft
LIBFT_LIB	=	libft.a
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

VIS_GIT		=	https://github.com/o-reo/push_swap_visualizer.git
VIS_DIR		=	./visualizer
VIS_EXE		=	$(VIS_DIR)/build/bin/visualizer

all: $(NAME)

$(NAME): $(LIBFT) $(SOURCE)
	@cd libft && make
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCE) ./libft/libft.a

$(LIBFT):
	git clone $(LIBFT_GIT) $(LIBFT_DIR); make -C $(LIBFT_DIR)

libclean:
	rm -rf $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

vis: $(NAME) $(VISEXE)
	$(VISEXE)

visclean:
	rm -rf $(VIS_DIR)

$(VIS_DIR):
	git clone $(VIS_GIT) $(VIS_DIR); (cd $(VIS_DIR) && mkdir build)

$(VIS_EXE): $(VIS_DIR)
	(cd $(VIS_DIR)/build && cmake .. && make)


.PHONY: all clean fclean re clean_obj
