NAME		= fractol

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./src

INCLUDES	= -I./includes -I./libft -I./minilibx-linux

HEADER		= ./includes/fractol.h

LIBFT_DIR	=	libft

LIBFT		=	-Llibft -lft

MLX_DIR		=	minilibx-linux

MLX			=	-L./minilibx-linux -lmlx -lm -lX11 -lXext

SRC			= $(shell find $(SRC_DIR) -name "*.c")

OBJ			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

BUILD_DIR	= ./build

all: build lib minilibx $(NAME)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c Makefile $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a Makefile
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBFT) $(MLX)

lib:
	make -C $(LIBFT_DIR)

minilibx:
	make -C $(MLX_DIR)

build:
	mkdir -p ${BUILD_DIR}

clean:
	rm -rf $(BUILD_DIR)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
	make -C $(LIBFT_DIR) re
