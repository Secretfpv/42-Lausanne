NAME = push_swap
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT_DIR = libft

SRC_FILES = $(addprefix ft_, $(addsuffix .c, push_swap push_swap_functions push_swap_functions2))

OBJS := $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT_DIR)
		@cp ${LIBFT_DIR}/libft.a .
		mv libft.a push_swap
		ar rcs $(NAME) $(OBJS)
		@echo "compilation done"
	
%.o: %.c
		$(CC) $(CCFLAGS) -c $< -o $@ -I $(LIBFT_DIR)

clean:
		$(RM) $(OBJS)
		@make clean -C ${LIBFT_DIR}
		@echo "Clean done"

fclean: clean
		$(RM) $(NAME)
		$(RM) ${LIBFT_DIR}/libft.a
		@echo "Fclean done"

re: fclean all

.PHONY: clean fclean re