/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:10:26 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/26 20:28:56 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_hooks(mlx_key_data_t keydata, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_ESCAPE)
        {
            //free the map matrix
            //free the mx window with mlx_terminate(game->mlx)
            //free the image in the 2D array mlx_image_t
            //exit(EXIT_SUCCESS); this's NOT an error
        }
        if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
        {
            game->next.y = game->current.y - 1;
            game->next.x = game->current.x;
        }
        else if (keydata.key  == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
        {
            game->next.x = game->current.x - 1;
            game->next.y = game->current.y;
        }
        else if (keydata.key  == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
        {
            game->next.y = game->current.y + 1;
            game->next.x = game->current.x;
        }
        else if (keydata.key  == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
        {
            game->next.x = game->current.x + 1;
            game->next.y = game->current.y;
        }
        else
            return ;
        if (game->map->matrix[game->next.y][game->next.x] != '1')
            move_player(game);
    }
}
void close_hook(void *param)
{
    t_game *game;

    game = (t_game *)param;
    //free the map matrix
    //free the mx window with mlx_terminate(game->mlx)
    //free the image in the 2D array mlx_image_t
    //exit(EXIT_SUCCESS); this's NOT an error
}