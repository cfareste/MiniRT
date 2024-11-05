#pragma once
#include "parser/parser.h"
#include "../scene_settings.h"

int	try_parse_scene_setting(t_parser_ctx *ctx, char **params,
			t_scene_settings *settings);
