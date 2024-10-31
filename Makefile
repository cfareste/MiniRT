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
        DEFINES += -D LINUX=1
		export LINUX=1
    endif
    ifeq ($(UNAME_S),Darwin)
        DEFINES += -D DARWIN=1
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
SRCS = src/miniRT_bonus.c \
	src/window/window.c \
	src/window/helpers/window_helper_bonus.c \
	src/render/render_bonus.c \
	src/render/helpers/render_helper_bonus.c \
	src/render/renderer/renderer_bonus.c \
	src/render/loader/loader_bonus.c \
	src/render/loader/helpers/loader_helper/loader_helper_bonus.c \
	src/render/loader/helpers/bar_helper/bar_helper.c \
	src/render/loader/thread/loader_thread_bonus.c \
	src/render/scene/scene.c \
	src/render/scene/parser/scene_parser.c \
	src/render/scene/camera/camera.c \
	src/render/scene/camera/parser/camera_parser.c \
	src/render/scene/figure/figure.c \
	src/render/scene/figure/parser/figure_parser.c \
	src/render/scene/figure/helpers/figure_helpers.c \
	src/render/scene/figure/types/cylinder/cylinder.c \
	src/render/scene/figure/types/cylinder/helpers/cylinder_helper.c \
	src/render/scene/figure/types/plane/plane.c \
	src/render/scene/figure/types/plane/parser/plane_parser.c \
	src/render/scene/figure/types/sphere/sphere.c \
	src/render/scene/figure/types/cone/cone.c \
	src/render/scene/light/light.c \
	src/render/scene/light/parser/light_parser.c \
	src/render/scene/light/utils/light_utils.c \
	src/render/scene/light/ambient_light/ambient_light.c \
	src/render/ray/ray.c \
	src/render/ray/helpers/ray_helper.c \
	src/render/utils/color/color.c \
	src/render/utils/coordinates/coordinates.c \
	src/render/utils/vector/vector.c \
	src/render/utils/vector/parser/vector_parser.c \
	src/render/utils/vector/operation.c \
	src/render/utils/point/point.c \
	src/render/utils/reference_system/reference_system.c \
	src/utils/size/size.c \
	src/utils/errors.c \
	src/utils/file_utils.c \
	src/utils/images_bonus.c \
	src/parser/parser.c \

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
	mkdir -p web
	emcc -O3 $(INCLUDES) -pthread $(SRCS) \
    -o ./web/index.html \
	-I lib/mlx/include \
    lib/mlx/src/mlx_put_pixel.c \
	lib/mlx/src/mlx_exit.c \
	lib/mlx/src/textures/mlx_xpm42.c \
	lib/mlx/src/textures/mlx_texture.c \
	lib/mlx/src/textures/mlx_png.c \
	lib/mlx/src/mlx_init.c \
	lib/mlx/src/mlx_monitor.c \
	lib/mlx/src/mlx_loop.c \
	lib/mlx/src/mlx_cursor.c \
	lib/mlx/src/utils/mlx_error.c \
	lib/mlx/src/utils/mlx_utils.c \
	lib/mlx/src/utils/mlx_list.c \
	lib/mlx/src/utils/mlx_compare.c \
	lib/mlx/src/mlx_window.c \
	lib/mlx/src/mlx_mouse.c \
	lib/mlx/src/mlx_images.c \
	lib/mlx/src/mlx_keys.c \
	lib/mlx/src/font/mlx_font.c \
	lib/mlx/lib/glad/glad.c \
	lib/mlx/lib/png/lodepng.c \
	lib/mlx/build/mlx_vert_shader.c \
	lib/mlx/build/mlx_frag_shader.c \
	lib/libft/ft_strnstr.c \
	lib/libft/ft_strings.c \
	lib/libft/ft_isdigit.c \
	lib/libft/ft_putstr_fd.c \
	lib/libft/ft_lstadd_front_bonus.c \
	lib/libft/ft_printf_complex_parses.c \
	lib/libft/ft_lstdelone_bonus.c \
	lib/libft/ft_closest_multiple.c \
	lib/libft/ft_lstadd_back_bonus.c \
	lib/libft/get_next_line_utils.c \
	lib/libft/ft_strlcpy.c \
	lib/libft/ft_strlen.c \
	lib/libft/ft_lstmap_bonus.c \
	lib/libft/ft_printf_complex_padding_helper.c \
	lib/libft/ft_memcmp.c \
	lib/libft/ft_putnbr.c \
	lib/libft/ft_printf_flags_utils.c \
	lib/libft/ft_clamp.c \
	lib/libft/ft_filename.c \
	lib/libft/ft_putnbr_fd.c \
	lib/libft/ft_strchr.c \
	lib/libft/ft_printf.c \
	lib/libft/ft_striteri.c \
	lib/libft/ft_bzero.c \
	lib/libft/ft_strjoin.c \
	lib/libft/ft_isascii.c \
	lib/libft/ft_memcpy.c \
	lib/libft/ft_lstclear_bonus.c \
	lib/libft/get_next_line.c \
	lib/libft/ft_isprint.c \
	lib/libft/number_utils.c \
	lib/libft/ft_putendl_fd.c \
	lib/libft/ft_stroccurrences.c \
	lib/libft/ft_printf_padding_helper.c \
	lib/libft/ft_toupper.c \
	lib/libft/ft_lstiter_bonus.c \
	lib/libft/ft_split.c \
	lib/libft/ft_putchar.c \
	lib/libft/ft_printf_parses.c \
	lib/libft/ft_strrchr.c \
	lib/libft/ft_lstlast_bonus.c \
	lib/libft/ft_isalpha.c \
	lib/libft/ft_memchr.c \
	lib/libft/ft_putchar_fd.c \
	lib/libft/ft_memset.c \
	lib/libft/ft_substr.c \
	lib/libft/ft_strncmp.c \
	lib/libft/ft_matrix.c \
	lib/libft/ft_sort.c \
	lib/libft/ft_strmapi.c \
	lib/libft/ft_strtrim.c \
	lib/libft/ft_lstsize_bonus.c \
	lib/libft/ft_atod.c \
	lib/libft/ft_memmove.c \
	lib/libft/ft_override_val.c \
	lib/libft/ft_lstnew_bonus.c \
	lib/libft/ft_split_set.c \
	lib/libft/ft_putstr.c \
	lib/libft/ft_strlcat.c \
	lib/libft/ft_calloc.c \
	lib/libft/ft_strdup.c \
	lib/libft/ft_printf_format_helper.c \
	lib/libft/ft_atoi.c \
	lib/libft/ft_isalnum.c \
	lib/libft/ft_itoa.c \
	lib/libft/ft_tolower.c \
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
