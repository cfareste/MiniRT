/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:14:28 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/10 13:14:56 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MLX42.h"
#include "render/utils/point/point.h"

typedef enum job_type
{
	PUT_STR,
}	t_job_type;

typedef struct s_job	t_job;

typedef struct s_job
{
	t_job_type	type;
	void		*mlx;
	void		*args;
	int			required;
	void		*(*routine)(void *);
	t_job		*prev;
	t_job		*next;
}	t_job;

t_job	*new_job(t_job_type type, void *args, int required);

void	exec_job(t_job *job, mlx_t *mlx);
