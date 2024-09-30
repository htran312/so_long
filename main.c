/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:26:23 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/30 19:09:23 by htran-th         ###   ########.fr       */
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
    check_map(&map);
    ft_bzero(&game, sizeof(game));
    game.map = &map;
    start_game(&game);
    exit_game(&game, "Exit game!", EXIT_SUCCESS);
}
