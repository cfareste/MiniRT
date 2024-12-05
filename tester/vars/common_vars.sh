#! /bin/bash

#---# Colors #---#
DEF_COLOR="\033[0m"
WHITE_BOLD="\033[1;39m"
BLACK_BOLD="\033[1;30m"
RED_BOLD="\033[1;31m"
GREEN_BOLD="\033[1;32m"
YELLOW_BOLD="\033[1;33m"
BLUE_BOLD="\033[1;34m"
PINK_BOLD="\033[1;35m"
CYAN_BOLD="\033[1;36m"

WHITE="\033[0;39m"
BLACK="\033[0;30m"
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
PINK="\033[0;35m"
CYAN="\033[0;36m"
#----------------#


#---# Macros #---#
DELETE_LINE="\033[2K\r"
#----------------#


#----# Dirs #----#
SRC=src
TESTER=tester
TEST_GROUP_DIR=test_group
#----------------#


#--# UseCases #--#
SCENE_SETTINGS_UC="$TESTER/$TEST_GROUP_DIR/scene_settings/use_cases/scene_settings_use_cases"
RENDER_SETTINGS_UC="$TESTER/$TEST_GROUP_DIR/render_settings/use_cases/render_settings_use_cases"
WINDOW_SETTINGS_UC="$TESTER/$TEST_GROUP_DIR/window_settings/use_cases/window_settings_use_cases"
AMBIENTAL_UC="$TESTER/$TEST_GROUP_DIR/ambiental/use_cases/ambiental_use_cases"
CAMERA_UC="$TESTER/$TEST_GROUP_DIR/camera/use_cases/camera_use_cases"
LIGHT_UC="$TESTER/$TEST_GROUP_DIR/light/use_cases/light_use_cases"
FIGURE_UC="$TESTER/$TEST_GROUP_DIR/figure/use_cases/figure_use_cases"
OPTIONAL_UC="$TESTER/$TEST_GROUP_DIR/optional/use_cases/optional_use_cases"
MISC_UC="$TESTER/$TEST_GROUP_DIR/misc/use_cases/misc_use_cases"
#----------------#


#---# Scenes #---#
TEST_SCENE="tester/test_scene.rt"
#----------------#


#--# Defaults #--#
DEFAULT_CAMERA="C	0,0,0	0,0,-1	60	0	1"
DEFAULT_AMBIENTAL="A	1	255,255,255"
DEFAULT_FIGURE="sp		0,0,10		2		255,255,255"
#---------------–#


#----# Misc #----#
HEADER=$CYAN"╔════════════════════════════════════════════════════════════════════════════════╗\n\
║                           "$BLUE"Welcome to "$PINK_BOLD"Amethyst"$BLUE" tester"$CYAN"                           ║\n\
╚════════════════════════╦══════════════════════════════╦════════════════════════╝\n\
                         ║            "$YELLOW_BOLD"miniRT"$CYAN"            ║\n\
                         ╚══════════════════════════════╝"$DEF_COLOR"\n"
PROGRAM="miniRT"
WRONG_ICON="✘"
CORRECT_ICON="✔"
EXIT_FAILURE=1
EXIT_SUCCESS=130
#----------------#


#---# OLDIFS #---#
OLDIFS="$IFS"
#----------------#
