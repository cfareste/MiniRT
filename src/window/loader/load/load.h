/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:11:01 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:54:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../loader.h"
#include <pthread.h>

typedef struct s_load
{
	pthread_t	thread;
	t_loader	*loader;
}	t_load;

void	*minirt_load_routine(t_load *load);

t_load	*new_loader_load(t_loader *loader);

void	clean_load(t_loader *loader);
