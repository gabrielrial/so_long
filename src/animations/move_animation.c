/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:19:19 by grial             #+#    #+#             */
/*   Updated: 2024/09/01 18:43:09 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	move_animation(t_game *game)
{
	int	img_width;
	int	img_height;

	mlx_destroy_image(game->mlx_ptr, game->map.img_player);
	game->map.img_player = mlx_xpm_file_to_image(game->mlx_ptr, 
			"textures/player/player_move.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, 
		game->map.img_player, game->player.pos_x * SIZE, 
		game->player.pos_y * SIZE);
	while (game->n_frames <= 2000)
		game->n_frames++;
}
