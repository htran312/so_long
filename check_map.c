/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:38:30 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/25 22:39:31 by htran-th         ###   ########.fr       */
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
        {
            ft_printf("Error\nNot a rectangle map!\n");
            free_arr (map->matrix);
            free_arr (map->matrix_dup);
            exit (EXIT_FAILURE);
        }
        y++;
    }
    map->cols = temp_cols;
    if (map->rows > 120 || map->cols > 120)
    {
        ft_printf("Error\nMap parsing: map is too large!\n");
        free_arr (map->matrix);
        free_arr (map->matrix_dup);
        exit (EXIT_FAILURE);
    }
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
        {
            ft_printf("Error\nNot surrounded by wall!\n");
            free_arr (map->matrix);
            free_arr (map->matrix_dup);
            exit (EXIT_FAILURE);
        }
        x++;
    }
    while (y < map->rows)
    {
        if (map->matrix[y][0] != '1' || map->matrix[y][map->cols - 1] != '1')
        {
            ft_printf("Error\nNot surrounded by wall!\n");
            free_arr (map->matrix);
            free_arr (map->matrix_dup);
            exit (EXIT_FAILURE);
        }
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
                else
                    x++;
            }
            else
            {
                ft_printf ("Error\nWrong element(s) in the map\n");
                free_arr (map->matrix);
                free_arr (map->matrix_dup);
                exit (EXIT_FAILURE);
            }
        }
        y++;
    }
    if (map->exit_count != 1 || map->player_count != 1 || map->collectible_count < 1)
    {
        ft_printf ("Error\nInvalid number of element(s)\n");
        free_arr (map->matrix);
        free_arr (map->matrix_dup);
        exit (EXIT_FAILURE);
    }
}

static void flood_fill(t_map *map, int y, int x)
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

static void check_map_path(t_map *map)
{
    flood_fill(map, map->start.y, map->start.x);
    free_arr(map->matrix_dup);
    if (map->collectible_count != map->collectible_path)
    {
        ft_printf ("Error\nNo valid path to all collectibles!\n");
        free_arr (map->matrix);
        exit (EXIT_FAILURE);
    }
    if (map->collectible_path != 1)
    {
        ft_printf ("Error\nNo or more than one exit!\n");
        free_arr (map->matrix);
        exit (EXIT_FAILURE);
    }
}