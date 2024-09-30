/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:18:10 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/30 19:26:58 by htran-th         ###   ########.fr       */
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
