CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rsc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
