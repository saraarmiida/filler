NAME = visualiser
LIBNAME = libft.a 
LIBFT = ../libft                                                                            
FLAGS = -Wall -Wextra -Werror
FRAME = -framework OpenGL -framework AppKit
LIB = -L minilibx/ -lmlx
SRC = srcs/main.c \
		srcs/draw.c \
		srcs/read_input.c  \
		srcs/test.c

all: $(NAME)

$(NAME): $(LIBNAME)
	gcc ../libft/libft.a $(SRC) $(LIB) $(FRAME) -o $(NAME)

$(LIBNAME):
	make -C $(LIBFT)

clean:
	make clean -C $(LIBFT)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
