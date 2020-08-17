# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spentti <spentti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 14:03:19 by spentti           #+#    #+#              #
#    Updated: 2020/08/17 17:30:50 by spentti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = spentti.filler

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

INC = includes/filler.h

SRC = srcs/main.c \
	srcs/heat_map.c \
	srcs/place.c \
	srcs/read.c \
	srcs/utils.c \
	srcs/test.c \
	srcs/trim_piece.c

all: $(NAME)

$(NAME):
	@echo "Compiling library..."
	@make -C libft
	@echo "Compiling filler..."
	@gcc $(FLAGS) $(SRC) $(LIBFT) -I $(INC) -o $(NAME)

clean:
	@echo "Removing library object files..."
	@make clean -C libft

fclean: clean
	@echo "Removing library..."
	@make fclean -C libft
	@echo "Removing executable..."
	@rm -f $(NAME)

re: fclean all

visualiser: all
	make -C visualiser
