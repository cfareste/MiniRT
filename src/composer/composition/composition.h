/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:27:17 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/12 17:51:59 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../composer.h"

typedef struct s_composition
{
	t_composer	*composer;

	int			create_new_file;
}	t_composition;

void	*composition_routine(t_composition *composition);