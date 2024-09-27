/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:18:10 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/27 17:16:24 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_map *map, int y, int x)
{
    //base case
    if (map->matrix_dup[y][x] == '1')
        return ;
    if (map->matrix_dup[y][x] == 'C')
        map->collectible_path++;
    else if (map->matrix_dup[y][x] == 'E')
    {
        map->exit.x = x;
        map->exit.y = y;
        map->exit_path++;
    }
    map->matrix_dup[y][x] = '1';
    flood_fill(map, y + 1, x);
    flood_fill(map, y - 1, x);
    flood_fill(map, y, x + 1);
    flood_fill(map, y, x - 1);
}

void count_elements(t_map *map, int y, int x)
{
    if (map->matrix[y][x] == 'C')
        map->collectible_count++;
    else if (map->matrix[y][x] == 'E')
        map->exit_count++;
    else if (map->matrix[y][x] == 'P')
    {
        map->start.x = x;
        map->start.y = y;
        //printf("x=%d, y=%d\n", x, y);
        //map->start = (t_point){x, y};
        //printf("map->start::x=%d, y=%d\n", map->start.x, map->start.y);
        map->player_count++;
    }
}

void calculate_image_size(t_game *game)
{
    game->image_size.x = game->map->window_w / game->map->cols;
    game->image_size.y = game->map->window_h / game->map->rows;
    if (game->image_size.x <= game->image_size.y)
        game->render_pixel = game->image_size.x;
    else
        game->render_pixel = game->image_size.y;
}
mlx_image_t *png_to_image(t_game *game, const char *path)
{
    mlx_texture_t *texture;
    mlx_image_t *img;
    
    //load
    texture = mlx_load_png(path);
    if (!texture)
    {
        ft_printf("Error\nFailed to load texture file!\n");
        if (game->mlx)
            mlx_terminate(game->mlx);
        int i = 0;
        while (i < PNG_NUM)
        {
            if (game->image)
            {
                if (game->image[i])
                    mlx_delete_image(game->mlx, game->image[i]);
                i++;
                free (game->image);
            }
        }
        free (game->map->matrix);
        exit (EXIT_FAILURE);
    }
    //convert
    img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);
    if (!img)
    {
        ft_printf("Error\nFailed to convert texture to image!\n");
        if (game->mlx)
            mlx_terminate(game->mlx);
        int i = 0;
        while (i < PNG_NUM)
        {
            if (game->image)
            {
                if (game->image[i])
                    mlx_delete_image(game->mlx, game->image[i]);
                i++;
                free (game->image);
            }
        }
        free (game->map->matrix);
        exit (EXIT_FAILURE);
    }
    //resize
    if (!mlx_resize_image(img, game->render_pixel, game->render_pixel))
    {
        ft_printf ("Error\nFailed to resize image to fit the window!\n");
        int i = 0;
        while (i < PNG_NUM)
        {
            if (game->image)
            {
                if (game->image[i])
                    mlx_delete_image(game->mlx, game->image[i]);
                i++;
                free (game->image);
            }
        }
        if (game->mlx)
            mlx_terminate(game->mlx);
        free (game->map->matrix);
        exit (EXIT_FAILURE);
    }
    return (img);
}
void image_to_window(t_game *game, mlx_image_t *img, int col, int row)
{
    if (mlx_image_to_window(game->mlx, img, col * game->render_pixel, row * game->render_pixel) < 0)
    {
        ft_printf("Error\nFailed to render image to window!\n");
        int i = 0;
        while (i < PNG_NUM)
        {
            if (game->image)
            {
                if (game->image[i])
                    mlx_delete_image(game->mlx, game->image[i]);
                i++;
                free (game->image);
            }
        }
        if (game->mlx)
            mlx_terminate(game->mlx);
        free (game->map->matrix);
        exit (EXIT_FAILURE);
    }
}