CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
INC = fdf.h
SRCS =	fdf.c fdf_utils.c parsing.c file_check.c readmap.c readmap_utils.c \
		error.c \
		./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
NAME = fdf

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(OBJS) -o $(NAME)
# $(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all