/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:41:55 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/24 19:56:26 by htran-th         ###   ########.fr       */
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

# define PNG_NUM 5

# define PLAYER "./textures/player/meow000.png"
# define COLLECTIBLE "./textures/collectible/meal.png"
# define EXIT_PATH "./textures/exit/box.png"
# define SPACE "./textures/color_background_53.png"
# define WALL "./textures/wall/scratcher.png"

typedef enum e_object
{
    P,
    C,
    E,
    S,
    W,
}   t_object;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_image
{
    int image_w;
    int image_h;
    mlx_image_t	*space;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit_close;
	mlx_image_t	*exit_open;
	mlx_image_t	*start;
	mlx_image_t	*player;
}   t_image;

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


void start_game(t_game *game);
mlx_image_t *png_to_image(t_game *game, const char *path);
void image_to_window(t_game *game, mlx_image_t *img, int row, int col);

#endif