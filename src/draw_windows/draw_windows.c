/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:41:02 by grial             #+#    #+#             */
/*   Updated: 2024/09/08 14:10:18 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	draw_windows(t_game *game)
{
	draw_map(game);
	put_score(game);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	if (game->map.map[game->player.pos_y][game->player.pos_x] == 'A')
	{
		ft_printf("You Lost!");
		destroy_game(game);
	}
	x = 0;
	y = 0;
	mlx_clear_window(game->mlx_ptr, game->mlx_window);
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, 
				hook_img(game, game->map.map[y][x]), x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, 
		game->mlx_window, game->map.img_player, 
		game->player.pos_x * SIZE, game->player.pos_y * SIZE);
}

void	*hook_img(t_game *game, char c)
{
	if (c == '1')
		return (game->map.img_wall);
	if (c == 'C')
		return (game->map.img_collectible);
	if (c == 'E')
		return (game->map.img_portal);
	if (c == 'P')
		return (game->map.img_empty);
	if (c == '0')
		return (game->map.img_empty);
	if (c == 'A')
		return (game->map.img_enemy);
	return (0);
}

void	put_score(t_game *game)
{
	char	*moves;
	char	*coins;

	coins = NULL;
	moves = ft_itoa(game->counter.moves);
	mlx_string_put(game->mlx_ptr, game->mlx_window, 0, 
		game->map.size_y - 7, 500, "Moves:");
	mlx_string_put(game->mlx_ptr, game->mlx_window, 50, 
		game->map.size_y - 7, 500, moves);
	if (game->map.size_x > 150)
	{
		coins = ft_itoa(game->counter.collectibles);
		mlx_string_put(game->mlx_ptr, game->mlx_window, 100, 
			game->map.size_y - 7, 500, "Coins left: ");
		mlx_string_put(game->mlx_ptr, game->mlx_window, 175, 
			game->map.size_y - 7, 500, coins);
	}
	free(moves);
	free(coins);
}
