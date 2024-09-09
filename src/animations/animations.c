/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:57:54 by grial             #+#    #+#             */
/*   Updated: 2024/09/04 19:11:43 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	animations(t_game *game)
{
	usleep(100000);
	game->n_frames++;
	if (game->n_frames % 6 == 0)
	{
		update_enemy_position(game);
		load_animation(game, "textures/player/player_stand_1.xpm", 
			"textures/enemy/enemy_1.xpm");
		game->n_frames = 0;
	}
	else if (game->n_frames % 3 == 0)
		load_animation(game, "textures/player/player_stand_2.xpm", 
			"textures/enemy/enemy_2.xpm");
	draw_windows(game);
	return (1);
}

int	load_animation(t_game *game, char *player_path, char *enemy_path)
{
	int	img_width;
	int	img_height;

	if (game->map.img_player)
		mlx_destroy_image(game->mlx_ptr, game->map.img_player);
	if (game->map.img_enemy)
		mlx_destroy_image(game->mlx_ptr, game->map.img_enemy);
	game->map.img_player = mlx_xpm_file_to_image(game->mlx_ptr, 
			player_path, &img_width, &img_height);
	game->map.img_enemy = mlx_xpm_file_to_image(game->mlx_ptr, 
			enemy_path, &img_width, &img_height);
	if (!game->map.img_player || !game->map.img_enemy)
		return (0);
	return (1);
}
