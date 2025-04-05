MAKEFLAGS	+= --no-print-directory

RED			:= \e[31m
GREEN		:= \e[32m
YELLOW		:= \e[33m
BLUE		:= \e[34m
MAGENTA		:= \e[35m
CYAN		:= \e[36m
WHITE		:= \e[37m
BOLD		:= \e[1m
UNDERLINE	:= \e[4m
RESET		:= \e[0m

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

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER) Makefile
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "  ✅ ${GREEN}fract-ol/$<${RESET}"

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBFT) $(MLX)
	@echo "${YELLOW}Fract-ol Done!${RESET} 📿\n"

lib:
	@make -C $(LIBFT_DIR)

configure:
	@make -C $(MLX_DIR) --no-print-directory > /dev/null

mlxclean:
	@echo "🗑  ${RED}Minilibx Clining...${RESET}"
	@make -C $(MLX_DIR) clean --no-print-directory > /dev/null

build:
	@mkdir -p ${BUILD_DIR}/fractals

clean:
	@echo "🗑  ${RED}Remove Object Files...${RESET}"
	@rm -rf $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "🗑  ${RED}Remove Executable Files...${RESET}"


re: fclean mlxclean configure all