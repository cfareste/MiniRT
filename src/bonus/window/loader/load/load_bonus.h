/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:11:01 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../loader_bonus_bonus.h"
#include <pthread.h>

typedef struct s_load
{
	pthread_t	thread;
	t_loader	*loader;
}	t_load;

void	*minirt_load_routine(t_load *load);

t_load	*new_loader_load(t_loader *loader);

void	clean_load(t_loader *loader);
