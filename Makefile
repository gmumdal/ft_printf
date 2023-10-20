CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = *.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rsc $@ $(OBJS)

$(OBJS) :
	$(CC) $(CFLAGS) -c $(SRCS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
