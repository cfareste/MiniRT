/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:14:28 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 17:34:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"

typedef enum job_type
{
	ANON_JOB,
	TITLE_JOB,
	DESTROY_JOB,
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
