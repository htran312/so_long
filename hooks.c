/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:10:26 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/30 19:04:07 by htran-th         ###   ########.fr       */
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
            exit_game(game, "Exit game!",EXIT_SUCCESS);
        if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
            game->next = (t_point){game->current.x, game->current.y - 1};
        else if (keydata.key  == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
            game->next = (t_point){game->current.x - 1, game->current.y};
        else if (keydata.key  == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
            game->next = (t_point){game->current.x, game->current.y + 1};
        else if (keydata.key  == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
            game->next = (t_point){game->current.x + 1, game->current.y};
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
    exit_game(game, "Exit game!", EXIT_SUCCESS);
}