# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spentti <spentti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 14:03:19 by spentti           #+#    #+#              #
#    Updated: 2020/03/03 16:48:14 by spentti          ###   ########.fr        #
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
	srcs/utils.c

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) $(SRC) $(LIBFT) -I $(INC) -o $(NAME)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all