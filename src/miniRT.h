/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:57:08 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/11/10 20:25:19 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define PROGRAM_NAME "miniRT"
# define PROGRAM_NAME_SUFF " · miniRT"
# ifndef DARWIN
#  define DARWIN 0
# endif
# ifndef LINUX
#  define LINUX 0
# endif
# include "window/window.h"

void	destroy(t_window *window);

#endif
