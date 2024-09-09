/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:30:20 by grial             #+#    #+#             */
/*   Updated: 2024/09/04 18:37:12 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	move_up(t_game *game)
{
	if (game->map.map[game->player.pos_y - 1][game->player.pos_x] != '1')
	{
		game->player.pos_y--;
		return (1);
	}
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map.map[game->player.pos_y + 1][game->player.pos_x] != '1')
	{
		game->player.pos_y++;
		return (1);
	}
	return (0);
}

int	move_right(t_game *game)
{
	if (game->map.map[game->player.pos_y][game->player.pos_x + 1] != '1')
	{
		game->player.pos_x++;
		return (1);
	}
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map.map[game->player.pos_y][game->player.pos_x - 1] != '1')
	{
		game->player.pos_x--;
		return (1);
	}
	return (0);
}

int	valid_move(t_game *game, int key)
{
	if (key == LEFT && !move_left(game))
		return (0);
	else if (key == UP && !move_up(game))
		return (0);
	else if (key == RIGHT && !move_right(game))
		return (0);
	else if (key == DOWN && !move_down(game))
		return (0);
	game->counter.moves++;
	return (1);
}
