NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_BASE = ft_printf.c ft_printf_utils.c


OBJS_BASE = $(SRCS_BASE:.c=.o)
OBJS = $(OBJS_BASE)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean