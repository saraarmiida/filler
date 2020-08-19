# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spentti <spentti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 16:35:38 by spentti           #+#    #+#              #
#    Updated: 2020/08/19 19:10:46 by spentti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual

SRCS =	srcs/main.c \
		srcs/draw.c \
		srcs/input.c \
		srcs/tools.c	   

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@echo "Compiling visualiser..."
	@gcc -o $(NAME) $(FLAGS) $(SRCS) -L includes/minilibx/ -lmlx -framework OpenGL -framework AppKit ../libft/libft.a

clean:

fclean: clean
	@echo "Removing executable..."
	@rm -f $(NAME)

re: fclean all
