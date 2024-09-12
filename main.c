/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:26:23 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/11 22:51:48 by htran-th         ###   ########.fr       */
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

static void calculate_columns(char *map_name, t_map *map)
{
    char *line;
    int fd;
    int len;

    fd = open(map_name, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\nFailed to open map.\n");
        exit (EXIT_FAILURE);
    }
    line = get_next_line(fd);
    if (!line)
    {
        if (errno != 0)
        {
            perror("Error\n");
            close (fd);
            exit(EXIT_FAILURE);
        }
        ft_printf("Error\nEmpty/invalid map\n");
        close (fd);
        exit (EXIT_FAILURE);
    }
    map->cols = ft_strlen(line);
    if (line[map->cols - 1] == '\n')
        map->cols--;
    free (line);
    close(fd);
}
static void calculate_rows(char *map_name, t_map *map)
{
    char *line;
    int fd;

    fd = open(map_name, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\nFailed to open map.\n");
        exit (EXIT_FAILURE);
    }
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
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
        if (ft_strlen(line) - 1 != map->cols)
        {
            ft_printf("Error\nNot a rectangle map!\n");
            free(line);
            close (fd);
            exit (EXIT_FAILURE);
        }
        map->rows++;
        free(line);
    }
    close(fd);
}

static void read_map(char *map_name, t_map *map)
{
    calculate_columns(map_name, map);
    calculate_rows(map_name, map);
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
