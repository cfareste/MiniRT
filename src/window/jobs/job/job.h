/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:14:28 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/29 18:18:01 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include <pthread.h>

typedef enum job_type
{
	ANON_JOB,
	IMG_RESIZE_JOB,
	TITLE_JOB,
	DESTROY_JOB,
	EXPORT_JOB,
}	t_job_type;

typedef struct s_window	t_window;

typedef struct s_job	t_job;

typedef struct s_job
{
	t_job_type			type;
	void				*mlx;
	void				*arg;
	int					required;
	int					(*run)(t_job *, t_window *);
	void				(*free)(t_job *);
	void				(*destroy)(t_job *);
	int					finished;
	pthread_mutex_t		finished_mutex;
	int					to_free;
	pthread_mutex_t		to_free_mutex;
	t_job				*next;
}	t_job;

t_job	*new_job(void);

void	wait_job(t_job *job, int (*check_proceed)(void *arg), void *arg);

void	job_set_to_free(t_job *job, int to_free);