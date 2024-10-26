#pragma once

void			compute_diffuse(t_ray *shadow_ray, t_hit_record *hit_record,
					t_light *light, t_color *color);

void			compute_specular(t_scene *scene, t_coordinates reflected,
					t_light *light, t_color *color);

t_coordinates	get_reflection(t_ray *shadow_ray, t_hit_record *hit_record);

void			apply_ambient_lighting(t_light *ambient, t_color *res);