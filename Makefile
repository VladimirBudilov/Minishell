NAME	= minishell

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g

SRC_PATH = sources/
OBJ_PATH = objects/
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

SRC		=  *.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/push_swap.h

all: $(OBJ_PATH) $(NAME) $(LIBFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_PATH)
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re
