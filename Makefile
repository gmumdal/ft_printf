CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c buf_func.c info_func.c csn_format.c di_format.c xp_format.c u_format.c util_func.c 
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rsc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

bonus :

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
