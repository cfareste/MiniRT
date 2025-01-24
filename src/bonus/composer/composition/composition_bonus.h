/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:27:17 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../composer_bonus.h"

typedef struct s_composition
{
	t_composer	*composer;
	int			create_new_file;
}	t_composition;

void	*composition_routine(t_composition *composition);
