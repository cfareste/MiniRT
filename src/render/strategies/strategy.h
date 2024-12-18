/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:36 by arcanava          #+#    #+#             */
/*   Updated: 2024/12/18 11:32:44 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef enum e_strategy
{
	PATHTRACING = 0,
	RAYTRACING,
	NORMAL_MAP,
	STRATEGIES_AMOUNT
}	t_strategy;