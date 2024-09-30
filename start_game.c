/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:09:50 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/30 19:25:19 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void window_init(t_game *game)
{
    int render_pixel;
    
    if (game->map->cols >= game->map->rows)
        render_pixel = MAX_PIXEL / ((game->map->cols / RANGE) + 1);
    else
        render_pixel = MAX_PIXEL / ((game->map->rows / RANGE) + 1);
    
    game->map->window_w = game->map->cols * render_pixel;
    game->map->window_h = game->map->rows * render_pixel;
    game->mlx = mlx_init(game->map->window_w, game->map->window_h, "so_long", true);
    if (!game->mlx)
        exit_game(game, mlx_strerror(mlx_errno), EXIT_FAILURE);
}

void start_game(t_game *game)
{
    game->current = game->map->start;
    window_init(game);
    image_init(game);
    map_display(game);
    mlx_key_hook(game->mlx, game_hooks, game);
    mlx_close_hook(game->mlx, close_hook, game);
    mlx_loop(game->mlx);
}