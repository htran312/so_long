/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:09:50 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/25 22:32:03 by htran-th         ###   ########.fr       */
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
        if (game->mlx)
            mlx_terminate(game->mlx);
        //try to use mlx_strerror to see which error happened
        exit (EXIT_FAILURE);
    }
}
static void image_init(t_game *game)
{
    calculate_image_size(game);
    game->image = ft_calloc(PNG_NUM, sizeof(mlx_image_t));
    if (!game->image)
    {
        ft_printf("Error\nMemory allocation for image(s) failed!\n");
        free_arr(game->map->matrix);
        //check if (game->mlx) then use mlx_terminate(game->mlx)
        if (game->mlx)
            mlx_terminate(game->mlx);
        //try to use mlx_strerror to see which error happened
        exit (EXIT_FAILURE);
    }
    game->image[P] = png_to_image(game, PLAYER);
    game->image[C] = png_to_image(game, COLLECTIBLE);
    game->image[E] = png_to_image(game, EXIT_PATH);
    game->image[S] = png_to_image(game, SPACE);
    game->image[W] = png_to_image(game, WALL);
}
static void map_display(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map->rows)
    {
        x = 0;
        while (x < game->map->cols)
        {
            if (game->map->matrix[y][x] == '1')
                image_to_window(game, game->image[W], x, y);
            else
            {
                image_to_window(game, game->image[S], x, y);
                if (game->map->matrix[y][x] == 'C')
                    image_to_window(game, game->image[C], x, y);
                else if (game->map->matrix[y][x] == 'E')
                    image_to_window(game, game->image[E], x, y);
            }
            x++;
        }
        y++;
    }
    image_to_window(game, game->image[P], game->current.x, game->current.y);
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
    //clean_and_exit(game); maybe do it in the main?
}