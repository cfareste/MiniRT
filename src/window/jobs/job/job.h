/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:14:28 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 15:30:09 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "render/utils/point/point.h"

typedef enum job_type
{
	UNKNOWN_JOB,
	TITLE_JOB,
}	t_job_type;

typedef struct s_window	t_window;

typedef struct s_job	t_job;

typedef struct s_job
{
	t_job_type	type;
	void		*mlx;
	void		*arg;
	int			required;
	void		(*run)(t_job *, t_window *);
	void		(*free)(t_job *);
	t_job		*next;
}	t_job;

t_job	*new_job(void);

void	exec_job(t_job *job, mlx_t *mlx);
