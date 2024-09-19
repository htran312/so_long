/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:09:50 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/19 22:23:29 by htran-th         ###   ########.fr       */
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
    //free everything necessary, at this point (probably) only matrix left
    {
        ft_printf ("Error\nFailed to set up game window!\n");
        free_arr(game->map->matrix);
        //game->mlx here is already NULL but later in the delete function,
        //check if (game->mlx) then use mlx_terminate(game->mlx)
        exit (EXIT_FAILURE);
    }
}
static void image_init(t_game *game)
{
    calculate_image_size(game);
    
    
    
}

void start_game(t_game *game)
{
    game->current = game->map->start;
    window_init(game);
    image_init(game);
}