/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_helper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:09:07 by arcanava          #+#    #+#             */
/*   Updated: 2025/01/25 15:52:39 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../exporter.h"
#include "../export/export.h"

int		is_exporter_active(t_exporter *exporter);

void	set_exporter_active(t_exporter *exporter, int active);

void	write_image(int fd, t_export *export, char *buff, int buff_len);
