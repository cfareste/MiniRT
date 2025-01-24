/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:53:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 16:18:28 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_bonus.h"
#include "utils/utils_bonus.h"

#ifdef DARWIN

void	get_thread_id(pthread_t *thread, uint64_t *id)
{
	if (pthread_threadid_np(*thread, id) != 0)
		throw_sys_error("Getting thread id");
}

#else

void	get_thread_id(pthread_t *thread, uint64_t *id)
{
	*id = *thread;
}

#endif
