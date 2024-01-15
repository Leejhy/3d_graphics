CC = cc#cc로 수정
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
INC = fdf.h
SRCS = 
OBJS = ${SRCS:.c=.o}
NAME = pipex

all : ${NAME}

${NAME} : $(OBJS) $(INC)
	$(CC) $(CFLAGS) -o ${NAME} ${OBJS}

%.o : %.c $(INC)
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all