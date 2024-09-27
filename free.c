/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:08:23 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/27 18:54:36 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void free_arr(char **ar)
{
    int i;

    i = 0;
    while (ar[i])
    {
        free (ar[i]);
        ar[i] = NULL;
        i++;
    }
    free (ar);
    ar = NULL;
}
static void clean_map(t_map *map)
{
    if (!map)
        return ;
    if (map->line)
    {
        free(map->line);
        map->line = NULL;
    }
    if (map->temp_matrix)
    {
        free(map->temp_matrix);
        map->temp_matrix = NULL;
    }
    if (map->matrix)
        free_arr(map->matrix);
    if (map->matrix_dup)
        free_arr(map->matrix_dup);
}
void map_error(t_map *map, char *message)
{
    clean_map(map);
    ft_printf("Error\n%s\n", message);
    exit(EXIT_FAILURE);
}
static void clean_game(t_game *game)
{
    int i;
    
    if (!game)
        return ;
    if (game->map)
        clean_map(game->map);
    if (game->image)
    {
        i = 0;
        while(i < PNG_NUM)
        {
        
            if (game->image[i])
                mlx_delete_image(game->mlx, game->image[i]);
            i++;
        }
        free (game->image);
    }
    if (game->mlx)
        mlx_terminate(game->mlx);
}
void game_error(t_game *game, char *message, int status)
{
    clean_game(game);
    ft_printf("Error\n%s\n", message);
    exit(status);
}
