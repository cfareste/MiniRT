/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:14:28 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 14:13:09 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "utils/async_flag/async_flag.h"

typedef enum job_type
{
	ANON_JOB,
	IMG_RESIZE_JOB,
	DESTROY_JOB,
	EXPORT_JOB,
}	t_job_type;

typedef struct s_window	t_window;

typedef struct s_job	t_job;

typedef struct s_job
{
	t_job_type			type;
	mlx_t				*mlx;
	void				*arg;
	int					required;
	int					(*run)(t_job *, t_window *);
	void				(*free)(t_job *);
	void				(*destroy)(t_job *);
	int					to_free;
	t_async_flag		removed;
	t_job				*next;
}	t_job;

t_job	*new_job(void);
