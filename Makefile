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
    # CCFLAGS += -D WIN32
    # ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
    #     CCFLAGS += -D AMD64
    # else
    #     ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
    #         CCFLAGS += -D AMD64
    #     endif
    #     ifeq ($(PROCESSOR_ARCHITECTURE),x86)
    #         CCFLAGS += -D IA32
    #     endif
    # endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        DEFINES += -D LINUX=1
		export LINUX=1
    endif
    ifeq ($(UNAME_S),Darwin)
        DEFINES += -D DARWIN=1
		export DARWIN=1
    endif
    # UNAME_P := $(shell uname -p)
    # ifeq ($(UNAME_P),x86_64)
    #     CCFLAGS += -D AMD64
    # endif
    # ifneq ($(filter %86,$(UNAME_P)),)
    #     CCFLAGS += -D IA32
    # endif
    # ifneq ($(filter arm%,$(UNAME_P)),)
    #     CCFLAGS += -D ARM
    # endif
endif


#----COMPILER----#
CC = cc
CCFLAGS += -Wall -Werror -Wextra -g -fsanitize=address


#----DIRS----#
BIN_DIR = bin/
SRC = src/
INCLUDES = -I$(SRC)


#----LIBS----#
LIB_DIR = lib

#----LIBFT----#
LIBFT_DIR = $(LIB_DIR)/libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
INCLUDES += -I$(LIBFT_DIR)


#----MLX----#
MLX_VERSION = 2.4.1
MLX_URL = https://github.com/codam-coding-college/MLX42/archive/refs/tags/v2.4.1.tar.gz
MLX_DIR = $(LIB_DIR)/mlx
MLX_BUILD_DIR = $(MLX_DIR)/build
MLX_COMP_FLAGS = -DDEBUG=1 -DGLFW_FETCH=1
MLX_LIB = $(MLX_BUILD_DIR)/libmlx42.a
INCLUDES += -I$(MLX_DIR)/include/MLX42
LIBRARIES += -L$(MLX_BUILD_DIR)
LIBRARIES_DEPS += -ldl -lm -lpthread -lmlx42
ifeq ($(UNAME_S), Darwin)
	LIBRARIES_DEPS += -lglfw3
	ifeq ($(shell test -f $(HOMEBREW_PREFIX)/lib/libglfw3.a || echo "not_installed"), not_installed)
		LIBRARIES += -L$(MLX_BUILD_DIR)/_deps/glfw-build/src
	else
		LIBRARIES += -L$(HOMEBREW_PREFIX)/lib
	endif
	LIBRARIES_DEPS += -framework Cocoa -framework OpenGL -framework IOKit
endif
ifeq ($(UNAME_S), Linux)
	LIBRARIES_DEPS += -lglfw
endif

#----WEB----#
WEB_URL = https://github.com/emscripten-core/emsdk/archive/refs/heads/main.zip
WEB_ROOT = $(LIB_DIR)/web


#----MACROS----#
export GNL_BUFFER_SIZE := 50000
ifeq ($(UNAME_S), Darwin)
	WINDOW_WIDTH := $(shell system_profiler -json SPDisplaysDataType 2>/dev/null | grep _spdisplays_resolution | awk 'NR==1{print substr($$3, 2, length($$3)) - 70}')
	WINDOW_HEIGHT := $(shell system_profiler -json SPDisplaysDataType 2>/dev/null | grep _spdisplays_resolution | awk 'NR==1{print $$5 - 70}')
	DEFINES += -D WINDOW_WIDTH=$(WINDOW_WIDTH) -D WINDOW_HEIGHT=$(WINDOW_HEIGHT)
endif
ifeq ($(UNAME_S), Linux)
	WINDOW_WIDTH := $(shell xrandr | grep "*" | awk '{ print $1 }' | cut -d'x' -f 1 | xargs)
	WINDOW_HEIGHT := $(shell xrandr | grep "*" | awk '{ print $1 }' | cut -d'x' -f 2 | cut -d' ' -f 1)
	DEFINES += -D WINDOW_WIDTH=$(WINDOW_WIDTH) -D WINDOW_HEIGHT=$(WINDOW_HEIGHT)
endif


#----VPATH----#
vpath %.c	$(SRC):\
			$(SRC)render:\
			$(SRC)render/scene:\
			$(SRC)render/scene/parser:\
			$(SRC)render/scene/camera:\
			$(SRC)render/scene/camera/parser:\
			$(SRC)render/scene/light:\
			$(SRC)render/scene/light/parser:\
			$(SRC)render/scene/light/utils:\
			$(SRC)render/scene/light/ambient_light:\
			$(SRC)render/scene/figure:\
			$(SRC)render/scene/figure/parser:\
			$(SRC)render/scene/figure/helpers:\
			$(SRC)render/scene/figure/types/cylinder:\
			$(SRC)render/scene/figure/types/cylinder/helpers:\
			$(SRC)render/scene/figure/types/plane:\
			$(SRC)render/scene/figure/types/plane/parser:\
			$(SRC)render/scene/figure/types/sphere:\
			$(SRC)render/scene/figure/types/cone:\
			$(SRC)parser:\
			$(SRC)render/renderer:\
			$(SRC)render/helpers:\
			$(SRC)render/loader:\
			$(SRC)render/ray:\
			$(SRC)render/ray/helpers:\
			$(SRC)render/loader/helpers/loader_helper:\
			$(SRC)render/loader/helpers/bar_helper:\
			$(SRC)render/loader/thread:\
			$(SRC)window:\
			$(SRC)window/helpers:\
			$(SRC)render/utils/color:\
			$(SRC)render/utils/coordinates:\
			$(SRC)render/utils/vector:\
			$(SRC)render/utils/vector/parser:\
			$(SRC)render/utils/point:\
			$(SRC)render/utils/reference_system:\
			$(SRC)utils/size/:\
			$(SRC)utils:\


#----SHARED----#
SRCS = miniRT_bonus.c \
	scene.c \
	errors.c \
	file_utils.c \
	light.c \
	color.c \
	camera.c \
	coordinates.c \
	figure.c \
	figure_helpers.c \
	cylinder.c \
	cylinder_helpers.c \
	plane.c \
	sphere.c \
	render_bonus.c \
	window.c \
	renderer_bonus.c \
	vector.c \
	operation.c \
	point.c \
	reference_system.c \
	render_helper_bonus.c \
	window_helper_bonus.c \
	loader_bonus.c \
	loader_helper_bonus.c \
	size.c \
	images_bonus.c \
	loader_thread_bonus.c \
	bar_helper.c \
	ray_helper.c \
	ray.c \
	light_utils.c \
	ambient_light.c \
	cone.c \
	parser.c \
	camera_parser.c \
	light_parser.c \
	scene_parser.c \
	figure_parser.c \
	vector_parser.c \
	plane_parser.c

OBJS = $(SRCS:%.c=$(BIN_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)



#----- R U L E S -----#

all:
	@$(MAKE) --no-print-directory make_libft
	@$(MAKE) --no-print-directory $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	@printf "$(BLUE)Linking objects and creating program...$(DEF_COLOR)\n"
	$(CC) $(CCFLAGS) $(DEFINES) $(OBJS) $(LIBFT_LIB) $(LIBRARIES) $(LIBRARIES_DEPS) -o $(NAME)
	@echo "$(GREEN)[✓] $(PINK)$(NAME)$(GREEN) created!!!$(DEF_COLOR)"

$(BIN_DIR)%.o: %.c Makefile
	@printf "$(CYAN)Compiling: $(PINK)$(notdir $<)...$(DEF_COLOR)\n"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CCFLAGS) $(DEFINES) $(INCLUDES) -MMD -c $< -o $@

clean: libft_clean
	@rm -rf $(BIN_DIR)
	@echo "$(RED)Binaries deleted$(DEF_COLOR)\n"

fclean: clean libft_fclean mlx_fclean
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
	printf "$(CYAN)Downloading $(PINK)mlx...$(DEF_COLOR)\n"
	curl -sOL $(MLX_URL)
	tar -xpf v$(MLX_VERSION).tar.gz
	rm -rf v$(MLX_VERSION).tar.gz
	mv -f MLX42-$(MLX_VERSION) $(MLX_DIR)
	echo "$(GREEN)[✓] $(PINK)mlx$(GREEN) downloaded!!!$(DEF_COLOR)\n"

$(MLX_LIB): | $(MLX_DIR)
	printf "$(CYAN)Compiling $(PINK)mlx...$(DEF_COLOR)\n"
	cd lib/mlx && cmake $(MLX_COMP_FLAGS) -Wsupress -Wno-dev -B build/ >/dev/null && make --no-print-directory -C build > /dev/null
	echo "$(GREEN)[✓] $(PINK)mlx$(GREEN) compiled!!!$(DEF_COLOR)\n"

mlx_fclean:
	rm -rf $(MLX_DIR)

download_web_deps:
	rm -rf $(WEB_ROOT)
	curl -sOL https://github.com/emscripten-core/emsdk/archive/refs/heads/main.zip
	mv main.zip $(LIB_DIR)
	cd $(LIB_DIR) && unzip main.zip
	rm -f $(LIB_DIR)/main.zip
	mv $(LIB_DIR)/emsdk-main $(WEB_ROOT)
	# source ./emsdk_env.sh

web: download_web_deps
	echo $(INCLUDES)
	mkdir -p web
	emcc -O3 $(INCLUDES) -pthread $(SRCS) \
    -o ./web/miniRT.js \
    ./build/libmlx42.a \
    -s USE_GLFW=3 -s USE_WEBGL2=1 -s FULL_ES3=1 -s WASM=1 \
    -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
    -s ALLOW_MEMORY_GROWTH

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
		mlx_fclean \
		web 

-include $(DEPS)
-include $(MDEPS)
-include $(BDEPS)
.SILENT:
