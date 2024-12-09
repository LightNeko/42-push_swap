NAME = push_swap

CC = gcc
CFLAGS = -Wextra -Werror -Wall

SRC_DIR = src
SRCS = main.c push_swap.c utils.c ft_lstnewcircular.c ft_lstadd_backcircular.c ft_lstlastcircular.c \
ft_lstclearcircular.c ft_lstdelonecircular.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(LIBFT_DIR)/includes -I includes

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

