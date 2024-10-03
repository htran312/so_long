/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:36:30 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/03 17:58:46 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_map_error(int fd, t_map *map, char *message)
{
	if (fd > 2)
	{
		close (fd);
		map_error(map, message);
	}
}

static void	read_map_helper(t_map *map)
{
	if (map->rows == 0)
		map_error(map, "Map is empty!");
	map->matrix = ft_split(map->temp_matrix, '\n');
	map->matrix_dup = ft_split(map->temp_matrix, '\n');
	if (!map->matrix || !map->matrix_dup)
		map_error(map, "Split failed!");
	free (map->temp_matrix);
	map->temp_matrix = NULL;
}

void	read_map(char *map_name, t_map *map)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		map_error(map, "Failed to open map!");
	while (1)
	{
		map->line = get_next_line(fd);
		if (!map->line)
		{
			if (errno != 0)
				handle_map_error(fd, map, strerror(errno));
			break ;
		}
		map->temp_matrix = ft_strjoin_gnl(map->temp_matrix, map->line);
		free (map->line);
		if (!map->temp_matrix)
			handle_map_error(fd, map, "Map line appending failed!");
		map->rows++;
	}
	close (fd);
	read_map_helper(map);
}
