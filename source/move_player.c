/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:44:35 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/03 17:53:38 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_collectible(t_game *game)
{
	int	i;
	int	rp;

	rp = game->render_pixel;
	i = 0;
	while (i < game->map->collectible_count)
	{
		if (game->image[C]->instances[i].y == game->current.y * rp
			&& game->image[C]->instances[i].x == game->current.x * rp)
		{
			game->image[C]->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}

void	move_player(t_game *game)
{
	game->current = game->next;
	ft_printf("Number of move: %d\n", ++game->moves);
	if (game->map->matrix[game->current.y][game->current.x] == 'C')
	{
		game->map->matrix[game->current.y][game->current.x] = '0';
		get_collectible(game);
		game->taken++;
		if (game->taken == game->map->collectible_count)
		{
			game->image[E]->instances[0].enabled = false;
			game->image[O]->instances[0].enabled = true;
		}
	}
	else if (game->map->matrix[game->current.y][game->current.x] == 'E'
		&& game->taken == game->map->collectible_count)
		exit_game(game, "You win!", EXIT_SUCCESS);
	game->image[P]->instances[0].y = game->current.y * game->render_pixel;
	game->image[P]->instances[0].x = game->current.x * game->render_pixel;
}
