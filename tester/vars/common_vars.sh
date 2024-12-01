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
SRC=src/
TESTER=tester/
#----------------#


#---# Scenes #---#
TEST_SCENE="tester/test_scene.rt"
#----------------#


#--# Defaults #--#
DEFAULT_CAMERA="C	0,0,0	0,0,-1	60	0	1"
DEFAULT_AMBIENTAL="A	1	255,255,255"
#---------------–#


#----# Misc #----#
header=$PINK_BOLD"Amethyst MiniRT tester"$DEF_COLOR
#----------------#
