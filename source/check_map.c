/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:38:30 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/02 21:38:31 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void check_map_shape(t_map *map)
{
    int y;
    int x;
    int temp_cols;

    y = 0;
    x = 0;
    temp_cols = ft_strlen(map->matrix[y]);
    while (y < map->rows)
    {
        x = ft_strlen(map->matrix[y]);
        if (x != temp_cols)
            map_error(map, "Not a rectangle map!");
        y++;
    }
    map->cols = temp_cols;
    if (map->rows > 120 || map->cols > 120)
        map_error(map, "Map parsing: map is too large!");
}

static void check_map_wall(t_map *map)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (x < map->cols)
    {
        if (map->matrix[0][x] != '1' || map->matrix[map->rows - 1][x] != '1')
            map_error(map, "Not surrounded by wall!");
        x++;
    }
    while (y < map->rows)
    {
        if (map->matrix[y][0] != '1' || map->matrix[y][map->cols - 1] != '1')
            map_error(map, "Not surrounded by wall!");
        y++;
    }
}

static void check_map_elements(t_map *map)
{
    int y;
    int x;

    y = 0;
    while (y < map->rows)
    {
        x = 0;
        while (x < map->cols)
        {
            if (ft_strchr("01CEP", map->matrix[y][x]) != NULL)
            {
                count_elements(map, y, x);
                x++;
            }
            else
                map_error(map, "Wrong element(s) in the map!");
        }
        y++;
    }
    if (map->exit_count != 1 || map->player_count != 1 || map->collectible_count < 1)
        map_error(map, "Invalid number of element(s)!");
}

static void check_map_path(t_map *map)
{
    flood_fill(map, map->start.y, map->start.x);
    free_arr(map->matrix_dup);
    map->matrix_dup = NULL;
    if (map->collectible_count != map->collectible_path)
        map_error(map, "No valid path to all collectibles and exit!");
    if (map->exit_path != 1)
        map_error(map, "No or more than one exit!");
}
void check_map(t_map *map)
{
    check_map_shape(map);
    check_map_wall(map);
    check_map_elements(map);
    check_map_path(map);
}