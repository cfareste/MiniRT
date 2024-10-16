NAME = miniRT

#----COLORS----#
DEF_COLOR = \033[0m
WHITE_BOLD = \033[1;39m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CYAN = \033[1;36m

#----OS COMPATIBILITY----#
ifeq ($(OS),Windows_NT)
    CCFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CCFLAGS += -D AMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CCFLAGS += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CCFLAGS += -D IA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D LINUX
		export LINUX=1
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -D OSX
		export DARWIN=1
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -D IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM
    endif
endif

#----COMPILER----#
CC = cc
CCFLAGS = -Wall -Werror -Wextra -g -fsanitize=address #-O3

#----DIRS----#
BIN_DIR = bin/
SRC = src/
INCLUDES = -I$(SRC)
INCLUDES += -I$(SRC)figure
INCLUDES += -I$(SRC)figure/types
INCLUDES += -I$(SRC)light
INCLUDES += -I$(SRC)scene
INCLUDES += -I$(SRC)scene/camera
INCLUDES += -I$(SRC)utils
INCLUDES += -I$(SRC)shared
INCLUDES += -I$(SRC)shared/coordinates


#----LIBS----#

#----LIBFT----#
LIBFT_DIR = lib/libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
INCLUDES += -I$(LIBFT_DIR)

#----MLX----#
MLX_DIR = lib/mlx
MLX_BUILD_DIR = $(MLX_DIR)/build
MLX_LIB = $(MLX_BUILD_DIR)/libmlx42.a
LIBRARIES += -L$(MLX_BUILD_DIR) -lmlx42
INCLUDES += -I$(MLX_DIR)/include/MLX42
LIBRARIES_DEPS += -ldl -lglfw -lm -lpthread
ifeq ($(UNAME_S), Darwin)
ifneq ($(filter arm%,$(UNAME_P)),)
LIBRARIES_DEPS += -L"/opt/homebrew/lib/"
else
LIBRARIES_DEPS += -L"/opt/homebrew/Cellar/glfw/$(GLFW_V)/lib/"
endif
endif


#----SHARED----#
SRCS = miniRT.c \
	scene.c \
	errors.c \
	file_utils.c \
	light.c \
	color.c \
	camera.c \
	coordinates.c \
	figure.c \
	cylinder.c \
	plane.c \
	sphere.c
OBJS = $(SRCS:%.c=$(BIN_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)

#----MACROS----#
export GNL_BUFFER_SIZE := 50000

#----VPATH----#
vpath %.c $(SRC):$(SRC)scene:$(SRC)scene/camera:$(SRC)utils:$(SRC)light:$(SRC)figure:$(SRC)shared/color:$(SRC)shared/coordinates:$(SRC)figure/types/cylinder:$(SRC)figure/types/plane:$(SRC)figure/types/sphere


#----- R U L E S -----#

all:
	@$(MAKE) --no-print-directory make_libft
	@$(MAKE) --no-print-directory $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	@printf "$(BLUE)Linking objects and creating program...$(DEF_COLOR)\n"
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_LIB) $(LIBRARIES) $(LIBRARIES_DEPS) -o $(NAME)
	@echo "$(GREEN)[✓] $(PINK)$(NAME)$(GREEN) created!!!$(DEF_COLOR)"

$(BIN_DIR)%.o: %.c Makefile
	@printf "$(CYAN)Compiling: $(PINK)$(notdir $<)...$(DEF_COLOR)\n"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CCFLAGS) $(INCLUDES) -MMD -c $< -o $@

clean: libft_clean
	@rm -rf $(BIN_DIR)
	@echo "$(RED)Binaries deleted$(DEF_COLOR)"

fclean: libft_fclean mlx_fclean clean
	@rm -rf $(NAME)
	@echo "$(RED)Executable deleted$(DEF_COLOR)\n"

re: fclean all

bonus:
	$(MAKE) --no-print-directory all BONUS=1

b: bonus

bonusre: fclean bonus

bre: bonusre

make_libft:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) bonus

libft_clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

libft_fclean:
	@echo "$(RED)Cleaning $(PINK)Libft$(RED)...$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

$(MLX_DIR):
ifeq ($(UNAME_S), Linux)
ifeq (sudo apt update,)
	sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
endif
endif
ifeq ($(UNAME_S), Darwin)
	brew install --formula glfw &>/dev/null
	brew install --formula cmake &>/dev/null
endif
	printf "$(CYAN)Downloading $(PINK)mlx...$(DEF_COLOR)\n"
	curl -sOL https://github.com/codam-coding-college/MLX42/archive/refs/tags/v2.3.4.tar.gz
	tar -xpf v2.3.4.tar.gz
	rm -rf v2.3.4.tar.gz
	mv -f MLX42-2.3.4 lib/mlx
	echo "$(GREEN)[✓] $(PINK)mlx$(GREEN) downloaded!!!$(DEF_COLOR)\n"

$(MLX_LIB): | $(MLX_DIR)
	printf "$(CYAN)Compiling $(PINK)mlx...$(DEF_COLOR)\n"
	cd lib/mlx && cmake -B build/ > /dev/null && make --no-print-directory -C build > /dev/null
	echo "$(GREEN)[✓] $(PINK)mlx$(GREEN) compiled!!!$(DEF_COLOR)\n"

mlx_fclean:
	rm -rf lib/mlx

.PHONY: all \
		clean \
		fclean \
		re \
		bonus \
		b \
		bonusre \
		bre \
		make_libft \
		libft_clean \
		libft_fclean \
		make_mlx \
		mlx_fclean 

-include $(DEPS)
-include $(MDEPS)
-include $(BDEPS)
.SILENT: