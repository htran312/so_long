/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:36:30 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/25 22:40:55 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(char *map_name, t_map *map)
{
    int fd;
    //open map file
    fd = open(map_name, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\nFailed to open map.\n");
        exit (EXIT_FAILURE);
    }

    //Allocate memory for the 2D array (matrix), calculate rows
    while (map->line)
    {
        map->line = get_next_line(fd);
        if (!map->line)
        {
            if (errno != 0)
            {
                perror("Error\n");
                close (fd);
                exit(EXIT_FAILURE); // Handle error appropriately (exit or return an error code)
            }
            // If it's just EOF (no error), break the loop
            break ;
        }
        map->temp_matrix = ft_strjoin_gnl(map->temp_matrix, map->line);
        free (map->line);
        if (!map->temp_matrix)
            //free everything necessary in map. temp_matrix is NOT an array!
        map->rows++;
    }
    close (fd);
    if (map->rows == 0)
    {
        ft_printf ("Error\nMap is empty!\n");
        free (map->temp_matrix);
        exit (EXIT_FAILURE);
    }
    map->matrix = ft_split(map->temp_matrix, '\n');
    map->matrix_dup = ft_split(map->temp_matrix, '\n');
    if (!map->matrix || !map->matrix_dup)
    {
        ft_printf("Error\nSplit failed!\n");
        free (map->temp_matrix);
        map->temp_matrix = NULL;
        exit(EXIT_FAILURE);
    }
    free (map->temp_matrix);
    map->temp_matrix = NULL;

    //calculate x (length of each matrix[y])) & compare them
    check_map_shape(map);
    check_map_wall(map);
    check_map_elements(map);
    check_map_path(map);
}
