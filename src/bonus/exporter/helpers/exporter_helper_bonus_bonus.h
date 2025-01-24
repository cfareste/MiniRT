/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_helper_bonus_bonus.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:09:07 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/24 11:59:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../exporter_bonus_bonus.h"
#include "../export/export_bonus.h"

int		is_exporter_active(t_exporter *exporter);

void	set_exporter_active(t_exporter *exporter, int active);

void	write_image(int fd, t_export *export, char *buff, int buff_len);
