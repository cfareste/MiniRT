/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:52:52 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/10/27 20:52:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

int	get_bar_total_width(int window_width);

int	get_bar_width(int window_width, double current, double total);

int	get_bar_height(int window_height);
