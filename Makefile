CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c buf_func.c info_func.c csn_format.c di_format.c xp_format.c u_format.c util_func.c 
OBJS = $(SRCS:.c=.o)
SRCS_B = ft_printf_bonus.c buf_func_bonus.c info_func_bonus.c csn_format_bonus.c di_format_bonus.c xp_format_bonus.c u_format_bonus.c util_func_bonus.c 
OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rsc $@ $^

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

bonus : $(OBJS_B)

$(OBJS_B) : $(SRCS_B)
	$(CC) $(CFLAGS) -c $^
	ar rsc $(NAME) $(OBJS_B)

clean :
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
