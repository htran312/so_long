/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:10:26 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/05 20:46:06 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	switch_player_direction(t_game *game, mlx_key_data_t keydata)
{
	game->image[L]->instances[0].enabled = false;
	game->image[R]->instances[0].enabled = false;
	game->image[U]->instances[0].enabled = false;
	game->image[D]->instances[0].enabled = false;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
	{
		game->next = (t_point){game->current.x - 1, game->current.y};
		game->image[L]->instances[0].enabled = true;
	}
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
	{
		game->next = (t_point){game->current.x + 1, game->current.y};
		game->image[R]->instances[0].enabled = true;
	}
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
	{
		game->next = (t_point){game->current.x, game->current.y - 1};
		game->image[U]->instances[0].enabled = true;
	}
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
	{
		game->next = (t_point){game->current.x, game->current.y + 1};
		game->image[D]->instances[0].enabled = true;
	}	
}

void	game_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			exit_game (game, "Exit game!", EXIT_SUCCESS);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			switch_player_direction(game, keydata);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			switch_player_direction(game, keydata);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			switch_player_direction(game, keydata);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			switch_player_direction(game, keydata);
		else
			return ;
		if (game->map->matrix[game->next.y][game->next.x] != '1')
			move_player(game);
	}
}

void	window_resize_hook(int width, int height, void *param)
{
	int		i;
	t_game	*game;

	game = (t_game *)param;
	game->map->window_w = width;
	game->map->window_h = height;
	i = 0;
	while (i < PNG_NUM)
	{
		if (game->image[i])
			mlx_delete_image(game->mlx, game->image[i]);
		i++;
	}
	free (game->image);
	game->image = NULL;
	image_init(game);
	map_display(game);
}

void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit_game(game, "Exit game!", EXIT_SUCCESS);
}
