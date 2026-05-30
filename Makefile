NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft


SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/stack_utils.c \
	$(SRC_DIR)/operations_swap.c \
	$(SRC_DIR)/operations_push.c \
	$(SRC_DIR)/operations_rotate.c \
	$(SRC_DIR)/operations_reverse.c \
    $(SRC_DIR)/parsing.c \
	$(SRC_DIR)/sort_small.c \
    $(SRC_DIR)/sort_large.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re