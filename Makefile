# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spentti <spentti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 14:03:19 by spentti           #+#    #+#              #
#    Updated: 2020/02/24 10:13:51 by spentti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = spentti.filler
LIBNAME = libft.a
LIBFT = libft
FLAGS = -Wall -Wextra -Werror
INC = includes/filler.h
SRC = srcs/main.c \
		srcs/c_double.c \
		srcs/c_hex.c \
		srcs/c_int.c \
		srcs/c_octal.c \
		srcs/c_pointer.c \
		srcs/c_unsigned.c \
		srcs/c_binary.c \
		srcs/conversions.c \
		srcs/ft_printf.c \
		srcs/modifiers.c \
		srcs/parse_format.c \
		srcs/utils.c \
		srcs/ft_ftoa.c

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc $(FLAGS) $(LIBNAME) $(SRC)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all