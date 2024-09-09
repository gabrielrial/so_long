/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:34:05 by grial             #+#    #+#             */
/*   Updated: 2024/09/08 14:14:33 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_game(t_game *game)
{
	game->n_frames = 0;
	game->mlx_ptr = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_ptr, game->map.size_x, 
			game->map.size_y, "so_long");
	load_images(game);
	create_enemy(game);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_loop_hook(game->mlx_ptr, animations, game);
	mlx_hook(game->mlx_window, DestroyNotify, ButtonPressMask, 
		destroy_game, game);
	mlx_loop(game->mlx_ptr);
}
