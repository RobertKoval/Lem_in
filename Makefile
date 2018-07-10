# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/15 14:19:53 by rkoval            #+#    #+#              #
#    Updated: 2018/07/10 14:42:14 by rkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c read_input.c manage_ants.c save_values.c algorithm.c move_ants.c\
		utillity.c validate_values.c graph/add_vertex.c queue/add_queue.c\
		queue/remove_queue.c graph/remove_graph.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INC = lem_in.h

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

LIBFT_DIR = libft/
LIBFT_INC = $(LIBFT_DIR)includes/
LIBFT = $(LIBFT_DIR)libft.a

CFLAGS = -Wall -Werror -Wextra -std=c11
CPPFLAGS = -Iincludes
LDFLAGS = -lft -L $(LIBFT_DIR)

# COLORS
RESET=		\033[0m
RED=		\033[31m
GREEN=		\033[32m
YELLOW=		\033[33m
BLUE=		\033[34m
MAGENTA=	\033[35m
CYAN=		\033[36m
WHITE=		\033[37m
BOLDRED=	\033[1m\033[31m
BOLDWHITE=	\033[1m\033[37m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(CPPFLAGS) $(LDFLAGS)
	@echo "$(GREEN)lem-in $(BOLDRED)made$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@mkdir -p obj/graph
	@mkdir -p obj/queue
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all