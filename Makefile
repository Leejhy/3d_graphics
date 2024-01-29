CC = cc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit
INC = graphics.h
SRCS =	main.c fdf_utils.c init.c error.c \
		file_check.c parsing.c readmap.c readmap_utils.c \
		rotation.c hook.c put_pixel.c \
		./read/read_line.c ./read/read_line_utils.c
OBJS = ${SRCS:.c=.o}
NAME = fdf
MLX_DIR = ./mlx

all :
	@make -C $(MLX_DIR)
	@make $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(OBJS) $(FRAMEWORK) -o $(NAME)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all