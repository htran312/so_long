/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:24:41 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/01 19:06:50 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void image_to_window(t_game *game, mlx_image_t *img, int col, int row)
{
    int px;

    px = game->render_pixel;
    if (mlx_image_to_window(game->mlx, img, col * px, row * px) < 0)
        exit_game(game, mlx_strerror(mlx_errno), EXIT_FAILURE);
}
void map_display(t_game *game)
{
    int y;
    int x;

    y = -1;
    while (++y < game->map->rows)
    {
        x = -1;
        while (++x < game->map->cols)
        {
            image_to_window(game, game->image[S], x, y);
            if (game->map->matrix[y][x] == '1')
                image_to_window(game, game->image[W], x, y);
            else if (game->map->matrix[y][x] == 'C')
                image_to_window(game, game->image[C], x, y);
            else if (game->map->matrix[y][x] == 'E')
            {
                image_to_window(game, game->image[O], x, y);
                game->image[O]->instances[0].enabled = false;
                image_to_window(game, game->image[E], x, y);
            }
        }
    }
    image_to_window(game, game->image[P], game->current.x, game->current.y);
}
