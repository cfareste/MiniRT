#pragma once

#include "../loader.h"

/**
 * @brief 
 * Draws progress bar into loader image.
 * @param loader loader instance where draw the progress bar
 * @param bar_width relative to progress in px
 * @param size loader image size 
 * 
 */
void	update_progress_bar(t_loader *loader, int bar_width, t_size size);

/**
 * @brief 
 * To be used on a thread. It listens to loader state change.
 * @param loader Loader instance to be listened
 * @return `NULL` is always returned indicating loader_routine death
 */
void	*loader_routine(t_loader *loader);

void	kill_loader_routine(t_loader *loader);