NAME = visualiser
LIBNAME = libft.a 
LIBFT = ../libft                                                                            
FLAGS = -Wall -Wextra -Werror
FRAME = -framework OpenGL -framework AppKit
LIB = -L /usr/local/lib -lmlx -I /usr/local/X11/include -L /usr/X11/lib -lX11 -lXext
SRC = srcs/*.c


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
