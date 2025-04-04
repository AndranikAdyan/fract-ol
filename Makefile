MAKEFLAGS	+= --no-print-directory

NAME		= fractol

LIBFT_DIR	= libs/libft

LIBFT		= -L./$(LIBFT_DIR) -lft

MLX_DIR		= libs/minilibx-linux

MLX			= -L./$(MLX_DIR) -lmlx -lm -lX11 -lXext

INCLUDES	= -I./includes -I./$(LIBFT_DIR) -I./$(MLX_DIR)

HEADER		= ./includes/fractol.h

CC			= cc

FLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

SRC_DIR		= ./src

SRC			= $(shell find $(SRC_DIR) -name "*.c")

OBJ			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

BUILD_DIR	= ./build

all: build lib $(NAME)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBFT) $(MLX)

lib:
	@make -C $(LIBFT_DIR)

minilibx:
	@make -C $(MLX_DIR)

build:
	mkdir -p ${BUILD_DIR}/fractals

clean:
	rm -rf $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean minilibx all
	make -C $(LIBFT_DIR) re
