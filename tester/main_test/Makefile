NAME = main_test


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
CCFLAGS += -Wall -Werror -Wextra -O3


#----DIRS----#
BIN_DIR = bin/
SRC = ../../src/
INCLUDES = -I$(SRC)
EXPORTS = ../../exports/


#----LIBS----#
LIBRARIES_DEPS = -lm

#----MLX----#
MLX_VERSION = 2.4.1
MLX_URL = https://github.com/codam-coding-college/MLX42/archive/refs/tags/v2.4.1.tar.gz
MLX_DIR = ../../lib/mlx
MLX_LIB = $(MLX_DIR)/include/MLX42.h
MLX_BUILD_DIR = $(MLX_DIR)/build
INCLUDES += -I$(MLX_DIR)/include/MLX42

#----LIBFT----#
LIBFT_DIR = ../../lib/libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
INCLUDES += -I$(LIBFT_DIR)

#----MACROS----#
export GNL_BUFFER_SIZE := 50000

#----VPATH----#
vpath %.c	$(SRC):\
			$(SRC)render:\
			$(SRC)scene:\
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
			$(SRC)scene/figure/parser:\
			$(SRC)scene/figure/parser/helpers:\
			$(SRC)scene/figure/operations:\
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
			$(SRC)scene/figure/types/cylinder/default:\
			$(SRC)scene/figure/types/cylinder/helpers:\
			$(SRC)scene/figure/types/cylinder/parser:\
			$(SRC)scene/figure/types/cylinder/pattern:\
			$(SRC)scene/figure/types/cylinder/texture:\
			$(SRC)scene/figure/types/plane:\
			$(SRC)scene/figure/types/plane/default:\
			$(SRC)scene/figure/types/plane/helpers:\
			$(SRC)scene/figure/types/plane/parser:\
			$(SRC)scene/figure/types/plane/pattern:\
			$(SRC)scene/figure/types/plane/texture:\
			$(SRC)scene/figure/types/sphere:\
			$(SRC)scene/figure/types/sphere/default:\
			$(SRC)scene/figure/types/sphere/parser:\
			$(SRC)scene/figure/types/sphere/pattern:\
			$(SRC)scene/figure/types/sphere/texture:\
			$(SRC)scene/figure/types/sphere/helpers:\
			$(SRC)scene/figure/types/cone:\
			$(SRC)scene/figure/types/cone/default:\
			$(SRC)scene/figure/types/cone/parser:\
			$(SRC)scene/figure/types/cone/pattern:\
			$(SRC)scene/figure/types/cone/texture:\
			$(SRC)scene/figure/types/disk:\
			$(SRC)scene/figure/types/disk/default:\
			$(SRC)scene/figure/types/disk/parser:\
			$(SRC)scene/figure/types/disk/texture:\
			$(SRC)scene/figure/types/quadrilater:\
			$(SRC)scene/figure/types/quadrilater/default:\
			$(SRC)scene/figure/types/quadrilater/helpers:\
			$(SRC)scene/figure/types/quadrilater/parser:\
			$(SRC)scene/figure/types/box:\
			$(SRC)scene/figure/types/box/default:\
			$(SRC)scene/figure/types/box/operations:\
			$(SRC)scene/figure/types/box/helpers:\
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
			$(SRC)window/jobs/job/types/title:\
			$(SRC)window/jobs/job/types/destroy:\
			$(SRC)window/jobs/job/types/anonymous:\
			$(SRC)window/jobs/job/types/export:\
			$(SRC)window/jobs/job/types/image_resize:\
			$(SRC)window/textures:\
			$(SRC)window/textures/texture:\
			$(SRC)window/parser:\
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
			$(SRC)render/utils/vector/rotation:\
			$(SRC)render/utils/vector/parser:\
			$(SRC)render/utils/point:\
			$(SRC)render/utils/reference_system:\
			$(SRC)render/utils/iterators:\
			$(SRC)render/utils/thread:\
			$(SRC)render/utils/random:\
			$(SRC)render/parser:\
			$(SRC)render/events:\
			$(SRC)utils:\
			$(SRC)utils/size:\
			$(SRC)parser:\
			$(SRC)parser/helpers:\
			$(SRC)window/textures/parser:\
			$(SRC)scene/figure/types/cylinder/composer:\
			$(SRC)scene/figure/types/plane/composer:\
			$(SRC)scene/figure/types/sphere/composer:\
			$(SRC)scene/figure/types/cone/composer:\
			$(SRC)scene/figure/types/disk/composer:\
			$(SRC)scene/figure/types/quadrilater/composer:\
			$(SRC)scene/figure/types/box/composer:\

#----SHARED----#
SRCS =	main_test.c \
		file_utils.c \
		light.c \
		color.c \
		color_operations.c \
		coordinates.c \
		figure.c \
		figure_helpers.c \
		cylinder.c \
		cylinder_helpers.c \
		cylinder_parser.c \
		plane.c \
		sphere.c \
		vector.c \
		operation.c \
		point.c \
		reference_system.c \
		ray_helper.c \
		ray.c \
		light_utils.c \
		ambient_light.c \
		cone.c \
		cone_helpers.c \
		parser.c \
		camera_parser.c \
		light_parser.c \
		scene_parser.c \
		figure_parser.c \
		vector_parser.c \
		plane_parser.c \
		bump_map.c \
		scene_settings.c \
		scene_settings_parser.c \
		random.c \
		pattern.c \
		pattern_helpers.c \
		cone_parser.c \
		sphere_parser.c \
		sphere_pattern.c \
		plane_pattern.c \
		cylinder_pattern.c \
		cone_pattern.c \
		bump_map_helpers.c \
		bump_map_plane.c \
		bump_map_cylinder.c \
		bump_map_cone.c \
		bump_map_sphere.c \
		diffuse.c \
		metallic.c \
		plastic.c \
		glass.c \
		emissive.c \
		raytracing.c \
		pathtracing.c \
		strategies_shared.c \
		hit_record.c\
		parser_helper.c \
		render_parser.c \
		window_parser.c \
		camera_helper.c \
		camera.c \
		raytracing_helpers.c \
		pathtracing_helpers.c \
		material_helpers.c \
		figure_parser_helpers.c \
		disk.c \
		disk_parser.c \
		bump_map_disk.c \
		quadrilater.c \
		quadrilater_parser.c \
		box.c \
		box_helpers.c \
		box_parser.c \
		quadrilater_helpers.c \
		box_pattern.c \
		renderer_pixels.c \
		sky_box.c \
		textures_parser.c \
		figure_events.c \
		figure_events_helpers.c \
		sphere_default.c \
		plane_default.c \
		cylinder_default.c \
		cone_default.c \
		disk_default.c \
		quadrilater_default.c \
		box_default.c \
		plane_helpers.c \
		metallic_parser.c \
		plastic_parser.c \
		glass_parser.c \
		emissive_parser.c \
		metallic_default.c \
		plastic_default.c \
		glass_default.c \
		emissive_default.c \
		vector_rotation.c \
		box_operations.c \
		figure_operations.c \
		box_composer.c \
		cone_composer.c \
		cylinder_composer.c \
		disk_composer.c \
		plane_composer.c \
		quadrilater_composer.c \
		sphere_composer.c \
		string_utils.c \
		

OBJS = $(SRCS:%.c=$(BIN_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)



#----- R U L E S -----#

all:
	@$(MAKE) --no-print-directory make_libft
	@$(MAKE) --no-print-directory $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
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

fclean: clean libft_fclean
	@rm -rf $(NAME)
	@echo "$(RED)Executable deleted$(DEF_COLOR)\n"

re: fclean all

bonus:
	$(MAKE) --no-print-directory all BONUS=1

b: bonus

bonusre: fclean bonus

bre: bonusre

$(MLX_LIB): | $(MLX_DIR)

$(MLX_DIR):
	printf "$(CYAN)Downloading $(PINK)mlx...$(DEF_COLOR)\n"
	curl -sOL $(MLX_URL)
	tar -xpf v$(MLX_VERSION).tar.gz
	rm -rf v$(MLX_VERSION).tar.gz
	mv -f MLX42-$(MLX_VERSION) $(MLX_DIR)
	echo "$(GREEN)[✓] $(PINK)mlx$(GREEN) downloaded!!!$(DEF_COLOR)\n"

make_libft:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) bonus

libft_clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

libft_fclean:
	@echo "$(RED)Cleaning $(PINK)Libft$(RED)...$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

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

-include $(DEPS)
.SILENT:
