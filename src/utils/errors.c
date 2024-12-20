/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/12/06 17:47:35 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "window/window.h"
#include "libft.h"
#include <string.h>
#include <errno.h>

void	throw_error(char *msg)
{
	ft_printff(STDERR_FILENO, "%s: %s\n",
		PROGRAM_NAME, msg);
	exit(EXIT_FAILURE);
}

// TODO: Push destroy job!
void	throw_sys_error(char *msg)
{
	ft_printff(STDERR_FILENO, "%s: %s: %s\n",
		PROGRAM_NAME, msg, strerror(errno));
	exit(EXIT_FAILURE);
}
