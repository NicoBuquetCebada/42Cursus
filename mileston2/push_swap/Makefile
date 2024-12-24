NAME = push_swap
SRCS =		1.operations.c\
			2.operations.c\
			1.stack_utils.c\
			2.stack_utils.c\
			1.parser.c\
			2.parser.c\
			1.utils.c\
			2.utils.c\
			first_sort.c\
			push_swap_utils.c\
			push_swap.c\
			main.c

OBJS = $(SRCS:.c=.o)
INCL = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS) $(INCL)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re