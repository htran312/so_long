/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:08:23 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/02 18:30:40 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_arr(char **ar)
{
    int i;

    i = 0;
    
    if (!ar)
        return ;
    while (ar[i])
    {
        free (ar[i]);
        ar[i] = NULL;
        i++;
    }
    free (ar);
}
void clean_map(t_map *map)
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
    {
        free_arr(map->matrix);
        map->matrix = NULL;
    }
    if (map->matrix_dup)
    {
        free_arr(map->matrix_dup);
        map->matrix_dup = NULL;
    }
}
void map_error(t_map *map, char *message)
{
    clean_map(map);
    ft_printf("Error\n%s\n", message);
    exit(EXIT_FAILURE);
}
void clean_game(t_game *game)
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
void exit_game(t_game *game, const char *message, int status)
{
    clean_game(game);
    if (status == EXIT_FAILURE)
        ft_printf("Error\n%s\n", message);
    else
        ft_printf("%s\n", message);
    exit(status);
}
