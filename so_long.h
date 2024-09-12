/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:41:55 by htran-th          #+#    #+#             */
/*   Updated: 2024/09/11 19:44:11 by htran-th         ###   ########.fr       */
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
    int rows;
    int cols;
    int window_w;
    int window_h;
    int player_count;
    int exit_count;
    //int collectible_path;
    //int exit_path;
    int collectible_count;
    t_point	start;
	t_point	exit;
}   t_map;

typedef struct s_game_data
{
    mlx_t *mlx;
    t_map *map;
    t_image image;
    t_point current;
    t_point next;
    int taken;
    int moves;
}   t_game;




#endif