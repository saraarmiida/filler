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
	@gcc -o $(NAME) $(FLAGS) $(SRCS) -L includes/mlx/ -lmlx -framework OpenGL -framework AppKit ../libft/libft.a

clean:

fclean: clean
	@echo "Removing executable..."
	@rm -f $(NAME)

re: fclean all
