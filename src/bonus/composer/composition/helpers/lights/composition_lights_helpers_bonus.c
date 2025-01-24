/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition_lights_helpers_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:35:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composition_lights_helpers_bonus.h"
#include "utils/utils_bonus.h"
#include "libft.h"

int	fill_ambient(t_composer *composer, t_light *ambiental, char **buffer)
{
	if (!composer_is_alive(composer))
		return (1);
	push_str(buffer, "A ", throw_sys_error, "pushing ambiental setting string");
	join_format_str(buffer, NULL, ft_dtoa(ambiental->brightness, 3), SEP);
	join_format_str(buffer, NULL, colortoa(&ambiental->color), '\n');
	return (0);
}

int	fill_lights(t_composer *composer, t_light *lights, char **buffer)
{
	t_light	*light;

	if (!composer_is_alive(composer))
		return (1);
	light = lights;
	while (light && composer_is_alive(composer))
	{
		push_char(buffer, light->type, throw_sys_error, "pushing light type");
		push_char(buffer, SEP, throw_sys_error, "pushing whitespace");
		join_format_str(buffer, NULL, coordtoa(&light->position, 3), SEP);
		join_format_str(buffer, NULL, ft_dtoa(light->brightness, 2), SEP);
		join_format_str(buffer, NULL, colortoa(&light->color), '\n');
		light = light->next;
	}
	return (0);
}
