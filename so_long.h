/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:41:55 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/28 17:56:11 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include "MLX42.h"

# define MAX_PIXEL 160
# define RANGE 16

# define PNG_NUM 6

# define PLAYER "./textures/player/meow000.png"
# define COLLECTIBLE "./textures/collectible/meal.png"
# define EXIT_PATH_CLOSE "./textures/exit/exit_box_closed.png"
# define EXIT_PATH_OPEN "./textures/exit/exit_box_open.png"
# define SPACE "./textures/color_background_53.png"
# define WALL "./textures/wall/scratcher.png"

typedef enum e_object
{
    P,
    C,
    E,
    O,
    S,
    W,
}   t_object;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_map
{
    char **matrix;
    char **matrix_dup;
    char *line;
    char *temp_matrix;
    int rows;
    int cols;
    int window_w;
    int window_h;
    int player_count;
    int exit_count;
    int collectible_count;
    int exit_path;
    int collectible_path;
    t_point	start;
	t_point	exit;
}   t_map;

typedef struct s_game_data
{
    mlx_t *mlx;
    t_map *map;
    mlx_image_t **image;
    t_point image_size;
    t_point current;
    t_point next;
    int render_pixel;
    int taken;
    int moves;
}   t_game;

void read_map(char *map_name, t_map *map);
void check_map(t_map *map);
void flood_fill(t_map *map, int y, int x);
void count_elements(t_map *map, int y, int x);
void start_game(t_game *game);
mlx_image_t *png_to_image(t_game *game, const char *path);
void image_to_window(t_game *game, mlx_image_t *img, int row, int col);
void game_hooks(mlx_key_data_t keydata, void *param);
void close_hook(void *param);
void map_error(t_map *map, char *message);
void game_error(t_game *game, char *message, int status);

#endif