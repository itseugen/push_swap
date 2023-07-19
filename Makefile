# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 15:24:01 by eweiberl          #+#    #+#              #
#    Updated: 2023/07/19 16:19:15 by eweiberl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = push_swap.c ./operations/push_a_b.c testers.c ./operations/stack_init.c ./operations/helpers.c\
		./operations/onetilln.c ./operations/listops.c ./operations/rotate.c  ./operations/stackops.c ./operations/issorted.c\
		./operations/oplist.c ./operations/swap.c
SOURCE+= ./sorting/mergesort.c ./sorting/sorting.c ./sorting/mergesortlarge.c
SOURCE+= ./checks/check_input.c ./checks/ps_atoi.c

OBJDIR = ./objects
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SOURCES))

OBJS = $(SOURCE:.c=.o)

LIBFT_GIT	=	https://github.com/itseugen/c_library
LIBFT_DIR	=	./libft
LIBFT_LIB	=	libft.a
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

VIS_GIT		=	https://github.com/o-reo/push_swap_visualizer.git
VIS_DIR		=	./visualizer
VIS_EXE		=	$(VIS_DIR)/build/bin/visualizer

TESTER_GET	=	https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER		=	./ps_tester.pl


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	git clone $(LIBFT_GIT) $(LIBFT_DIR); make -C $(LIBFT_DIR)
	@cd libft && make

libclean:
	rm -rf $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

vis: $(VIS_EXE) $(NAME)
	$(VIS_EXE)

visclean:
	rm -rf $(VIS_DIR)

$(VIS_EXE):
	git clone $(VIS_GIT) $(VIS_DIR)
	cd $(VIS_DIR) && mkdir build
	cd $(VIS_DIR)/build && cmake .. && make

$(TESTER):
	curl $(TESTER_GET) -o $(TESTER)

3: $(NAME) $(TESTER)
	perl $(TESTER) 3 100

5: $(NAME) $(TESTER)
	perl $(TESTER) 5 100

100: $(NAME) $(TESTER)
	perl $(TESTER) 100 100

500: $(NAME) $(TESTER)
	perl $(TESTER) 500 100

.PHONY: all clean fclean re clean_obj
# NAME = push_swap

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# SOURCE = push_swap.c ./operations/push_a_b.c testers.c ./operations/stack_init.c ./operations/helpers.c\
# 		./operations/onetilln.c ./operations/listops.c ./operations/rotate.c  ./operations/stackops.c ./operations/issorted.c\
# 		./operations/oplist.c ./operations/swap.c
# SOURCE+= ./sorting/mergesort.c ./sorting/sorting.c ./sorting/mergesortlarge.c
# SOURCE+= ./checks/check_input.c ./checks/ps_atoi.c

# OBJDIR = ./objects
# OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SOURCES))

# OBJS = $(SOURCE:.c=.o)

# LIBFT_GIT	=	https://github.com/itseugen/c_library
# LIBFT_DIR	=	./libft
# LIBFT_LIB	=	libft.a
# LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

# VIS_GIT		=	https://github.com/o-reo/push_swap_visualizer.git
# VIS_DIR		=	./visualizer
# VIS_EXE		=	$(VIS_DIR)/build/bin/visualizer

# TESTER_GET	=	https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
# TESTER		=	./ps_tester.pl


# all: $(NAME)

# $(NAME): $(LIBFT) $(SOURCE)
# 	$(CC) $(CFLAGS) -o $(NAME) $(SOURCE) $(LIBFT)

# $(LIBFT):
# 	git clone $(LIBFT_GIT) $(LIBFT_DIR); make -C $(LIBFT_DIR)
# 	@cd libft && make

# libclean:
# 	rm -rf $(LIBFT_DIR)

# clean:
# 	@rm -f $(OBJS)
# 	@cd libft && make clean

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all

# vis: $(VIS_EXE) $(NAME)
# 	$(VIS_EXE)

# visclean:
# 	rm -rf $(VIS_DIR)

# $(VIS_EXE):
# 	git clone $(VIS_GIT) $(VIS_DIR)
# 	cd $(VIS_DIR) && mkdir build
# 	cd $(VIS_DIR)/build && cmake .. && make

# $(TESTER):
# 	curl $(TESTER_GET) -o $(TESTER)

# 3: $(NAME) $(TESTER)
# 	perl $(TESTER) 3 100

# 5: $(NAME) $(TESTER)
# 	perl $(TESTER) 5 100

# 100: $(NAME) $(TESTER)
# 	perl $(TESTER) 100 100

# 500: $(NAME) $(TESTER)
# 	perl $(TESTER) 500 100

# .PHONY: all clean fclean re clean_obj
