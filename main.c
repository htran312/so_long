/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:26:23 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/17 21:31:28 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void check_map_name(char *map_name)
{
    int len;
    int fd;
    
    if (!map_name || map_name[0] == '\0')
    {
        ft_printf("Error\nInvalid file name!\n");
        exit (EXIT_FAILURE);
    }
    len = ft_strlen(map_name);
    if (map_name[len - 1] != 'r' || map_name[len - 2] != 'e'
        || map_name[len - 3] != 'b' || map_name[len - 4] != '.')
    {
        ft_printf("Error\nNot a .ber file!\n");
        exit (EXIT_FAILURE);
    }
    fd = open(map_name, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\nFailed to open map.\n");
        exit (EXIT_FAILURE);
    }
    close(fd);
}

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
}

static void check_map_wall(t_map *map)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (x < map->cols)
    {
        if (map->matrix[0][x] != '1' || map->matrix[map->rows][x] != '1')
        {
            ft_printf("Error\nNot a valid map\n");
            free_arr (map->matrix);
            free_arr (map->matrix_dup);
            exit (EXIT_FAILURE);
        }
        x++;
    }
    while (y < map->rows)
    {
        if (map->matrix[y][0] != '1' || map->matrix[y][map->cols] != '1')
        {
            ft_printf("Error\nNot a valid map\n");
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
                    map->start = (t_point){x, y};
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
        map->exit_path++;
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
        ft_printf("Error\nNo valid path to all collectibles!\n");
        free_arr(map->matrix);
        exit (EXIT_FAILURE);
    }
    if (map->collectible_path != 1)
    {
        ft_printf("Error\nMap is not playable!\n")
    }
}

static void read_map(char *map_name, t_map *map)
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
    map->matrix = ft_split(map->temp_matrix, '\n');
    map->matrix_dup = ft_split(map->temp_matrix, '\n');
    if (!map->matrix || !map->matrix)
        //free everything necessary in map. The split function already cleaned
        //up after itself so maybe just set the matrix(s) to NULL? Also the
        //temp->matrix needs to be freed too
    free (map->temp_matrix);
    map->temp_matrix = NULL;

    //calculate x (length of each matrix[y])) & compare them
    check_map_shape(map);
    check_map_wall(map);
    check_map_elements(map);
    check_map_path(map);


}

int main(int argc, char **argv)
{
    t_game game;
    t_map map;
    
    if (argc != 2)
    {
        ft_printf("Error\nEnter as follow: ./so_long <MAP_PATH>\n");
        exit (EXIT_FAILURE);
    }
    ft_bzero(&map, sizeof(map));
    check_map_name(argv[1]);
    read_map(argv[1], &map);
    //map_init();
		//- checking if the map is "real map" (filename, can be opened or not)
		//- counting how many lines the map has: open the map and count how
			//many rows or lines are there so it knows how tall the map is.
		//- reading and build the map: the game takes each line in the map,
			//one-by-one, and makes it into a grid (2D array hello?!). At
			//each position (x,y), it will append the number corresponding
			//with what has been specified in the map: walls, open spaces and
			// the player's starting point.
		//- checking if the map follows the rules:
			//- Is the map not empty? (So there's something to play!)
			//- Is the map shaped like a rectangle or square?
			//- Is the map too big?
			//- Does the map have the right pieces (wall, spaces etc.)
			//- Are there walls arnd the edges of the map to keep everything inside?
			//- Is there at least one valid path to win?
			//- All good? - Initialize the player's current position.
    //window_init();
    //image_init();
        //- calculate img size
        //- load img
    //display_game();
        //- draw map to window;
        //- load png to window;
}
