/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:51:31 by grial             #+#    #+#             */
/*   Updated: 2024/09/04 19:10:11 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	win(t_game *game);
void	make_move(t_game *game, int y, int x);

int	move_player(int key, t_game *game)
{
	int	tmp_y;
	int	tmp_x;

	tmp_y = game->player.pos_y;
	tmp_x = game->player.pos_x;
	if (valid_move(game, key))
		make_move(game, tmp_y, tmp_x);
	else
		return (0);
	return (1);
}

void	make_move(t_game *game, int y, int x)
{
	if (game->map.map[game->player.pos_y][game->player.pos_x] == 'C')
		game->counter.collectibles--;
	if (game->map.map[game->player.pos_y][game->player.pos_x] == 'E' && 
	game->counter.collectibles == 0)
	{
		ft_printf("You Win!\nMoves: %i\n", game->counter.moves);
		destroy_game(game);
	}
	if (game->map.map[game->player.pos_y][game->player.pos_x] == 'A')
	{
		ft_printf("You Lost!\n");
		destroy_game(game);
	}
	if (game->map.map[game->player.pos_y][game->player.pos_x] == 'E' &&
	game->counter.collectibles != 0)
		game->map.map[game->player.pos_y][game->player.pos_x] = 'E';
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, 
			game->map.img_empty, x * SIZE, y * SIZE);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, 
			game->map.img_player, game->player.pos_x * SIZE, 
			game->player.pos_y * SIZE);
		game->map.map[game->player.pos_y][game->player.pos_x] = '0';
	}
}
