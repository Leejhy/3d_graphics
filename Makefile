CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
INC = fdf.h
SRCS = 
OBJS = ${SRCS:.c=.o}
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(OBJS) -LlibLmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -Imlx $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all