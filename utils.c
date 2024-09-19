/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:18:10 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/19 22:20:59 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void calculate_image_size(t_game *game)
{
    game->image.image_w = game->map->window_w / game->map->cols;
    game->image.image_h = game->map->window_h / game->map->rows;
    if (game->image.image_w <= game->image.image_h)
        game->render_pixel = game->image.image_w;
    else
        game->render_pixel = game->image.image_h;
}