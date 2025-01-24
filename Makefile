NAME = miniRT


#----COLORS----#
DEF_COLOR = \033[0m
WHITE_BOLD = \033[1;39m
BLACK = \033[1;30m
RED = \033[1;31m
RED_REGULAR = \033[0;31m
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
        CCFLAGS += -D LINUX=1
		export LINUX=1
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -D DARWIN=1
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
CCFLAGS += -Wall -Werror -Wextra -Ofast


#----DIRS----#
BIN_DIR = bin/
SRC = src/mandatory/
ifeq ($(BONUS), 1)
	SRC = src/bonus/
endif
INCLUDES = -I$(SRC)
EXPORTS = exports/


#----LIBS----#

#----LIBFT----#
LIBFT_DIR = lib/libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
INCLUDES += -I$(LIBFT_DIR)


#----MLX----#
MLX_VERSION = 2.4.1
MLX_URL = https://github.com/codam-coding-college/MLX42/archive/refs/tags/v2.4.1.tar.gz
MLX_DIR = lib/mlx
MLX_BUILD_DIR = $(MLX_DIR)/build
MLX_COMP_FLAGS = -DGLFW_FETCH=1 #-DDEBUG=1
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


#----MACROS----#
export GNL_BUFFER_SIZE := 50000
ifeq ($(UNAME_S), Darwin)
	WINDOW_WIDTH := $(shell system_profiler -json SPDisplaysDataType 2>/dev/null | grep _spdisplays_resolution | awk 'NR==1{print substr($$3, 2, length($$3)) - 70}')
	WINDOW_HEIGHT := $(shell system_profiler -json SPDisplaysDataType 2>/dev/null | grep _spdisplays_resolution | awk 'NR==1{print $$5 - 70}')
	CCFLAGS += -D WINDOW_WIDTH=$(WINDOW_WIDTH) -D WINDOW_HEIGHT=$(WINDOW_HEIGHT)
endif
ifeq ($(UNAME_S), Linux)
	WINDOW_WIDTH := $(shell xrandr | grep "*" | awk '{ print $1 }' | cut -d'x' -f 1 | xargs)
	WINDOW_HEIGHT := $(shell xrandr | grep "*" | awk '{ print $1 }' | cut -d'x' -f 2 | cut -d' ' -f 1)
	CCFLAGS += -D WINDOW_WIDTH=$(WINDOW_WIDTH) -D WINDOW_HEIGHT=$(WINDOW_HEIGHT)
endif


#----VPATH----#
vpath %.c	$(SRC):\
			$(SRC)render:\
			$(SRC)scene:\
			$(SRC)scene/selection:\
			$(SRC)scene/selection/helpers:\
			$(SRC)scene/parser:\
			$(SRC)scene/camera:\
			$(SRC)scene/camera/helpers:\
			$(SRC)scene/camera/parser:\
			$(SRC)scene/camera/events:\
			$(SRC)scene/light:\
			$(SRC)scene/light/parser:\
			$(SRC)scene/light/utils:\
			$(SRC)scene/light/ambient_light:\
			$(SRC)scene/figure:\
			$(SRC)scene/figure/events:\
			$(SRC)scene/figure/events/helpers:\
			$(SRC)scene/figure/operations:\
			$(SRC)scene/figure/parser:\
			$(SRC)scene/figure/parser/helpers:\
			$(SRC)scene/figure/helpers:\
			$(SRC)scene/figure/material:\
			$(SRC)scene/figure/material/helpers:\
			$(SRC)scene/figure/material/types:\
			$(SRC)scene/figure/material/types/diffuse:\
			$(SRC)scene/figure/material/types/emissive:\
			$(SRC)scene/figure/material/types/emissive/default:\
			$(SRC)scene/figure/material/types/emissive/parser:\
			$(SRC)scene/figure/material/types/glass:\
			$(SRC)scene/figure/material/types/glass/default:\
			$(SRC)scene/figure/material/types/glass/parser:\
			$(SRC)scene/figure/material/types/metallic:\
			$(SRC)scene/figure/material/types/metallic/default:\
			$(SRC)scene/figure/material/types/metallic/parser:\
			$(SRC)scene/figure/material/types/plastic:\
			$(SRC)scene/figure/material/types/plastic/default:\
			$(SRC)scene/figure/material/types/plastic/parser:\
			$(SRC)scene/figure/helpers/base_attributes:\
			$(SRC)scene/figure/types/cylinder:\
			$(SRC)scene/figure/types/cylinder/composer:\
			$(SRC)scene/figure/types/cylinder/default:\
			$(SRC)scene/figure/types/cylinder/helpers:\
			$(SRC)scene/figure/types/cylinder/parser:\
			$(SRC)scene/figure/types/cylinder/pattern:\
			$(SRC)scene/figure/types/cylinder/texture:\
			$(SRC)scene/figure/types/plane:\
			$(SRC)scene/figure/types/plane/composer:\
			$(SRC)scene/figure/types/plane/default:\
			$(SRC)scene/figure/types/plane/helpers:\
			$(SRC)scene/figure/types/plane/parser:\
			$(SRC)scene/figure/types/plane/pattern:\
			$(SRC)scene/figure/types/plane/texture:\
			$(SRC)scene/figure/types/sphere:\
			$(SRC)scene/figure/types/sphere/composer:\
			$(SRC)scene/figure/types/sphere/default:\
			$(SRC)scene/figure/types/sphere/parser:\
			$(SRC)scene/figure/types/sphere/pattern:\
			$(SRC)scene/figure/types/sphere/texture:\
			$(SRC)scene/figure/types/sphere/helpers:\
			$(SRC)scene/figure/types/cone:\
			$(SRC)scene/figure/types/cone/composer:\
			$(SRC)scene/figure/types/cone/default:\
			$(SRC)scene/figure/types/cone/parser:\
			$(SRC)scene/figure/types/cone/pattern:\
			$(SRC)scene/figure/types/cone/texture:\
			$(SRC)scene/figure/types/disk:\
			$(SRC)scene/figure/types/disk/composer:\
			$(SRC)scene/figure/types/disk/default:\
			$(SRC)scene/figure/types/disk/parser:\
			$(SRC)scene/figure/types/disk/texture:\
			$(SRC)scene/figure/types/quadrilater:\
			$(SRC)scene/figure/types/quadrilater/composer:\
			$(SRC)scene/figure/types/quadrilater/default:\
			$(SRC)scene/figure/types/quadrilater/helpers:\
			$(SRC)scene/figure/types/quadrilater/parser:\
			$(SRC)scene/figure/types/box:\
			$(SRC)scene/figure/types/box/composer:\
			$(SRC)scene/figure/types/box/default:\
			$(SRC)scene/figure/types/box/helpers:\
			$(SRC)scene/figure/types/box/operations:\
			$(SRC)scene/figure/types/box/parser:\
			$(SRC)scene/figure/types/box/pattern:\
			$(SRC)scene/figure/texture/bump_map:\
			$(SRC)scene/figure/texture/bump_map/helpers:\
			$(SRC)scene/figure/texture/texel:\
			$(SRC)scene/figure/pattern:\
			$(SRC)scene/figure/pattern/helpers:\
			$(SRC)scene/settings:\
			$(SRC)scene/settings/sky_box:\
			$(SRC)scene/settings/parser:\
			$(SRC)scene/figure/types/cone/helpers:\
			$(SRC)window:\
			$(SRC)window/helpers:\
			$(SRC)window/jobs:\
			$(SRC)window/jobs/job:\
			$(SRC)window/jobs/job/helpers:\
			$(SRC)window/jobs/job/types/destroy:\
			$(SRC)window/jobs/job/types/anonymous:\
			$(SRC)window/jobs/job/types/export:\
			$(SRC)window/jobs/job/types/image_resize:\
			$(SRC)window/textures:\
			$(SRC)window/textures/parser:\
			$(SRC)window/textures/texture:\
			$(SRC)window/parser:\
			$(SRC)window/cursor:\
			$(SRC)window/events:\
			$(SRC)window/loader:\
			$(SRC)window/loader/load:\
			$(SRC)window/loader/helpers:\
			$(SRC)window/loader/strategies/progress:\
			$(SRC)window/loader/strategies/progress/helpers:\
			$(SRC)window/loader/strategies/text:\
			$(SRC)window/controls:\
			$(SRC)render/renderer:\
			$(SRC)render/renderer/parts:\
			$(SRC)render/renderer/pixels:\
			$(SRC)render/helpers:\
			$(SRC)render/ray:\
			$(SRC)render/ray/helpers:\
			$(SRC)render/strategies:\
			$(SRC)render/strategies/shared:\
			$(SRC)render/strategies/raytracing:\
			$(SRC)render/strategies/pathtracing:\
			$(SRC)render/strategies/normal_map:\
			$(SRC)render/strategies/raytracing/helpers:\
			$(SRC)render/strategies/pathtracing/helpers:\
			$(SRC)render/utils/color:\
			$(SRC)render/utils/color/color_operations:\
			$(SRC)render/utils/coordinates:\
			$(SRC)render/utils/hit_record:\
			$(SRC)render/utils/vector:\
			$(SRC)render/utils/vector/parser:\
			$(SRC)render/utils/vector/rotation:\
			$(SRC)render/utils/point:\
			$(SRC)render/utils/reference_system:\
			$(SRC)render/utils/iterators:\
			$(SRC)render/utils/thread:\
			$(SRC)render/utils/random:\
			$(SRC)render/parser:\
			$(SRC)render/events:\
			$(SRC)render/progressive:\
			$(SRC)render/progressive/helpers:\
			$(SRC)utils:\
			$(SRC)utils/size:\
			$(SRC)utils/async_flag:\
			$(SRC)parser:\
			$(SRC)parser/helpers:\
			$(SRC)exporter:\
			$(SRC)exporter/image:\
			$(SRC)exporter/helpers:\
			$(SRC)exporter/export:\
			$(SRC)composer:\
			$(SRC)composer/composition:\
			$(SRC)composer/composition/helpers/figures:\
			$(SRC)composer/composition/helpers/lights:\
			$(SRC)composer/composition/helpers/settings:\
			$(SRC)composer/events:


#----SHARED----#
MSRCS = miniRT.c \
		window_helper.c \
		window.c \
		parser_helper.c \
		parser.c \
		camera.c \
		camera_parser.c \
		figure.c \
		figure_helpers.c \
		figure_parser.c \
		figure_parser_helpers.c \
		cylinder.c \
		cylinder_helpers.c \
		cylinder_parser.c \
		plane_parser.c \
		plane.c \
		sphere_parser.c \
		sphere.c \
		ambient_light.c \
		light.c \
		light_parser.c \
		light_utils.c \
		scene_parser.c \
		ray_helper.c \
		ray.c \
		renderer.c \
		raytracing_helpers.c \
		raytracing.c \
		strategies_shared.c \
		color.c \
		color_operations.c \
		coordinates.c \
		hit_record.c \
		point.c \
		reference_system.c \
		operation.c \
		vector_parser.c \
		vector_rotation.c \
		vector.c \
		render.c \
		errors.c \
		file_utils.c


BSRCS = miniRT_bonus.c \
	scene_bonus.c \
	errors_bonus.c \
	file_utils_bonus.c \
	light_bonus.c \
	color_bonus.c \
	color_operations_bonus.c \
	camera_bonus.c \
	coordinates_bonus.c \
	figure_bonus.c \
	figure_helpers_bonus.c \
	cylinder_bonus.c \
	cylinder_helpers_bonus.c \
	cylinder_parser_bonus.c \
	plane_bonus.c \
	sphere_bonus.c \
	render_bonus.c \
	window_bonus.c \
	renderer_bonus.c \
	vector_bonus.c \
	operation_bonus.c \
	point_bonus.c \
	reference_system_bonus.c \
	render_helper_bonus.c \
	window_helper_bonus.c \
	size_bonus.c \
	images_bonus.c \
	ray_helper_bonus.c \
	ray_bonus.c \
	light_utils_bonus.c \
	ambient_light_bonus.c \
	cone_bonus.c \
	cone_helpers_bonus.c \
	parser_bonus.c \
	camera_parser_bonus.c \
	light_parser_bonus.c \
	scene_parser_bonus.c \
	figure_parser_bonus.c \
	vector_parser_bonus.c \
	plane_parser_bonus.c \
	bump_map_bonus.c \
	scene_settings_bonus.c \
	scene_settings_parser_bonus.c \
	exporter_bonus.c \
	image_bonus.c \
	exporter_helper_bonus.c\
	random_bonus.c \
	thread_bonus.c \
	pattern_bonus.c \
	pattern_helpers_bonus.c \
	cone_parser_bonus.c \
	sphere_parser_bonus.c \
	sphere_pattern_bonus.c \
	plane_pattern_bonus.c \
	cylinder_pattern_bonus.c \
	cone_pattern_bonus.c \
	loader_bonus.c \
	jobs_bonus.c \
	job_bonus.c \
	destroy_job_bonus.c \
	anon_job_bonus.c \
	textures_bonus.c \
	textures_parser_bonus.c \
	export_job_bonus.c \
	bump_map_helpers_bonus.c \
	bump_map_plane_bonus.c \
	bump_map_cylinder_bonus.c \
	bump_map_cone_bonus.c \
	bump_map_sphere_bonus.c \
	export_bonus.c \
	diffuse_bonus.c \
	metallic_bonus.c \
	plastic_bonus.c \
	glass_bonus.c \
	emissive_bonus.c \
	raytracing_bonus.c \
	pathtracing_bonus.c \
	strategies_shared_bonus.c \
	hit_record_bonus.c\
	parser_helper_bonus.c \
	render_parser_bonus.c \
	window_parser_bonus.c \
	camera_helper_bonus.c \
	camera_events_bonus.c \
	raytracing_helpers_bonus.c \
	pathtracing_helpers_bonus.c \
	material_helpers_bonus.c \
	load_bonus.c \
	loader_helper_bonus.c \
	image_resize_job_bonus.c \
	loader_progress_bonus.c \
	loader_progress_helper_bonus.c \
	loader_text_bonus.c \
	job_helper_bonus.c\
	figure_parser_helpers_bonus.c \
	disk_bonus.c \
	disk_parser_bonus.c \
	bump_map_disk_bonus.c \
	quadrilater_bonus.c \
	quadrilater_parser_bonus.c \
	box_bonus.c \
	box_helpers_bonus.c \
	box_parser_bonus.c \
	quadrilater_helpers_bonus.c \
	box_pattern_bonus.c \
	normal_map_bonus.c \
	render_events_bonus.c \
	renderer_pixels_bonus.c \
	renderer_parts_bonus.c \
	sky_box_bonus.c \
	window_events_bonus.c \
	window_cursor_bonus.c \
	scene_selection_bonus.c \
	composer_bonus.c \
	composition_bonus.c \
	composer_events_bonus.c \
	figure_events_bonus.c \
	plane_helpers_bonus.c \
	sphere_default_bonus.c \
	plane_default_bonus.c \
	cylinder_default_bonus.c \
	cone_default_bonus.c \
	disk_default_bonus.c \
	quadrilater_default_bonus.c \
	box_default_bonus.c \
	figure_events_helpers_bonus.c \
	metallic_parser_bonus.c \
	plastic_parser_bonus.c \
	glass_parser_bonus.c \
	emissive_parser_bonus.c \
	metallic_default_bonus.c \
	plastic_default_bonus.c \
	glass_default_bonus.c \
	emissive_default_bonus.c \
	vector_rotation_bonus.c \
	box_operations_bonus.c \
	window_controls_bonus.c \
	figure_operations_bonus.c \
	async_flag_bonus.c \
	render_progressive_bonus.c \
	progressive_helper_bonus.c \
	string_utils_bonus.c \
	box_composer_bonus.c \
	cone_composer_bonus.c \
	cylinder_composer_bonus.c \
	disk_composer_bonus.c \
	plane_composer_bonus.c \
	quadrilater_composer_bonus.c \
	sphere_composer_bonus.c \
	composition_figures_helpers_bonus.c \
	composition_lights_helpers_bonus.c \
	composition_settings_helpers_bonus.c \
	scene_selection_helpers_bonus.c

SRCS = $(MSRCS)
ifeq ($(BONUS), 1)
	SRCS = $(BSRCS)
endif
OBJS = $(SRCS:%.c=$(BIN_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)



#----- R U L E S -----#

all:
	mkdir -p $(EXPORTS)
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

norm:
	printf "$(BLUE)Testing the norm in $(WHITE_BOLD)$(SRC)$(BLUE)...$(RED_REGULAR)\n"
	norminette $(SRC) | grep -v "OK" && printf "$(DEF_COLOR)" || printf "$(GREEN)[✓] Passed successfully!$(DEF_COLOR)\n"
	printf "$(BLUE)Testing the norm in $(WHITE_BOLD)$(LIBFT_DIR)$(BLUE)...$(RED_REGULAR)\n"
	norminette $(LIBFT_DIR) | grep -v "OK" && printf "$(DEF_COLOR)" || printf "$(GREEN)[✓] Passed successfully!$(DEF_COLOR)\n"

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
		norm

-include $(DEPS)
-include $(MDEPS)
-include $(BDEPS)
.SILENT:
