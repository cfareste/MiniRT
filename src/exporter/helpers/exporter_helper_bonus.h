/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_helper_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:09:07 by arcanava          #+#    #+#             */
/*   Updated: 2024/11/07 13:09:08 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../exporter_bonus.h"

int		is_exporter_active(t_exporter *exporter);

void	set_exporter_active(t_exporter *exporter, int active);
