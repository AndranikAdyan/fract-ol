MAKEFLAGS	+= --no-print-directory

RED				= \e[31m
GREEN			= \e[32m
YELLOW			= \e[33m
CYAN			= \e[36m
RESET			= \e[0m

NAME			= fractol

LIBFT_DIR		= libs/libft

LIBFT			= -L./$(LIBFT_DIR) -lft

MLX_DIR			= libs/minilibx-linux

MLX				= -L./$(MLX_DIR) -lmlx -lm -lX11 -lXext

INCLUDES		= -I./includes -I./$(LIBFT_DIR) -I./$(MLX_DIR)

HEADERS			= ./includes/fractol.h ./includes/keys.h ./includes/structs.h

CC				= cc

FLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address

SRC_DIR			= ./src

SRC				=	${SRC_DIR}/main.c \
					${SRC_DIR}/math.c \
					${SRC_DIR}/initilization.c \
					${SRC_DIR}/validation.c \
					${SRC_DIR}/animation.c \
					${SRC_DIR}/draw.c \
					${SRC_DIR}/hooks.c \
					${SRC_DIR}/julia_control.c \
					${SRC_DIR}/mouse_controls.c \
					${SRC_DIR}/controls.c\
					${SRC_DIR}/fractals/mandelbrot.c \
					${SRC_DIR}/fractals/julia.c \
					${SRC_DIR}/fractals/tricorn.c \
					${SRC_DIR}/fractals/celtic_mandelbar.c \
					${SRC_DIR}/fractals/burning_ship.c \
					${SRC_DIR}/fractals/newton.c \


OBJ				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

BUILD_DIR		= ./build

all: build lib $(NAME)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS) Makefile
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "  ✅ ${GREEN}fract-ol/$<${RESET}"

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBFT) $(MLX)
	@echo "${YELLOW}Fract-ol Done!${RESET} 📿\n\n"
	@echo "$(CYAN)╔════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║          $(YELLOW)FRACT-OL PROJECT$(CYAN)          ║$(RESET)"
	@echo "$(CYAN)║          $(YELLOW)Username: aadyan$(CYAN)          ║$(RESET)"
	@echo "$(CYAN)╚════════════════════════════════════╝$(RESET)"
	@echo "$(YELLOW)Usage:$(RESET)"
	@echo "$(GREEN)./fractol <fractal name>$(RESET)"
	@echo "Example: ./fractol mandelbrot"
	@echo "$(YELLOW)Fractals:$(RESET)"
	@echo "• mandelbrot"
	@echo "• julia"
	@echo "• tricorn"
	@echo "• celtic_mandelbar"
	@echo "• burning_ship"
	@echo "• newton"
	@echo "$(YELLOW)Controls:$(RESET)"
	@echo "Arrows     → move fractal"
	@echo "+ / -      → zoom in / out"
	@echo "Scroll     → zoom in / out"
	@echo "R          → reset fractal view"
	@echo "W A S D    → change Julia parameters"
	@echo "Space      → change colors"
	@echo "L          → lock animation"
	@echo "N / M      → something interesting :)"
	@echo "$(GREEN)Have fun exploring fractals!$(RESET)"

lib:
	@make -C $(LIBFT_DIR)

configure:
	@make -C $(MLX_DIR) --no-print-directory > /dev/null

mlxclean:
	@echo "🗑  ${RED}Minilibx Cleaning...${RESET}"
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

.PHONY: all lib configure mlxclean build clean fclean