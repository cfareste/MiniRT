/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:56:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:56:45 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"
#include <string.h>
#include <errno.h>

void	throw_error(char *msg)
{
	ft_printff(STDERR_FILENO, "Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	throw_sys_error(char *msg)
{
	ft_printff(STDERR_FILENO, "%s: %s: %s\n",
		PROGRAM_NAME, msg, strerror(errno));
	exit(EXIT_FAILURE);
}

void	throw_mlx_error(char *msg, const char *mlx_msg)
{
	ft_printff(STDERR_FILENO, "%s: %s: %s\n",
		PROGRAM_NAME, msg, mlx_msg);
	exit(EXIT_FAILURE);
}
