/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:53:10 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/07 11:45:10 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <pthread.h>

#ifdef DARWIN

void	get_thread_id(pthread_t *thread, uint32_t *id)
{
	pthread_threadid_np(*thread, (uint64_t *) id);
}

#else

void	get_thread_id(pthread_t *thread, uint32_t *id)
{
	*id = *thread;
}

#endif
