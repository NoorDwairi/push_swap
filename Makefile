NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iincludes -Ilibft

SRCS	= $(wildcard stratiges/*.c utils/*.c operations/*.c) main.c
OBJS	= $(SRCS:.c=.o)

LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re