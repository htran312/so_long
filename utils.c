/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:18:10 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/21 19:23:18 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void calculate_image_size(t_game *game)
{
    game->image_size.x = game->map->window_w / game->map->cols;
    game->image_size.y = game->map->window_h / game->map->rows;
    if (game->image_size.x <= game->image_size.y)
        game->render_pixel = game->image_size.x;
    else
        game->render_pixel = game->image_size.y;
}
mlx_texture_t *png_to_image(t_game *game, const char *path)
{
    
}