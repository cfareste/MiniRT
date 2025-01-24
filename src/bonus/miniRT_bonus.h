/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:08 by cfidalgo          #+#    #+#             */
/*   Updated: 2025/01/24 13:56:03 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H
# define PROGRAM_NAME "miniRT"
# define PROGRAM_NAME_SUFF " · miniRT"
# define FILE_EXTENSION ".rt"
# ifndef DARWIN
#  define DARWIN 0
# endif
# ifndef LINUX
#  define LINUX 0
# endif

# include "window/window_bonus.h"

void	main_destroy(t_window *window);

#endif
