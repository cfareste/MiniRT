/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:58:17 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/23 21:41:16 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

void		change_figure_material(t_figure *selection);

t_figure	*change_figure_type(t_scene *scene, t_figure *old_figure);
