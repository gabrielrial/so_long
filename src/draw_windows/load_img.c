/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:03:05 by grial             #+#    #+#             */
/*   Updated: 2024/09/01 18:40:38 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->map.img_wall = mlx_xpm_file_to_image(game->mlx_ptr, 
			"textures/wall/wall.xpm", &img_width, &img_height);
	game->map.img_enemy = mlx_xpm_file_to_image(game->mlx_ptr, 
			"textures/enemy/enemy_1.xpm", &img_width, &img_height);
	game->map.img_empty = mlx_xpm_file_to_image(game->mlx_ptr, 
			"textures/wall/empty.xpm", &img_width, &img_height);
	game->map.img_portal = mlx_xpm_file_to_image(game->mlx_ptr, 
			"textures/door/portal.xpm", &img_width, &img_height);
	game->map.img_player = mlx_xpm_file_to_image(game->mlx_ptr, 
			"textures/player/player_stand_1.xpm", &img_width, &img_height);
	game->map.img_collectible = mlx_xpm_file_to_image(game->mlx_ptr, 
			"textures/coin/coin_1.xpm", &img_width, &img_height);
}
