/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:36:54 by grial             #+#    #+#             */
/*   Updated: 2024/09/10 14:48:08 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_map(char **map);
void	free_list(t_enemy *enemy);

int	destroy_game(t_game *game)
{
	if (game->mlx_window)
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_window);
		mlx_destroy_window(game->mlx_ptr, game->mlx_window);
	}
	if (game->enemy)
		free_list(game->enemy);
	free_img(game);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	if (game->map.map)
		free_map(game->map.map);
	free(game);
	game = NULL;
	exit(0);
	return (0);
}

void	free_img(t_game *game)
{
	if (game->map.img_collectible)
		mlx_destroy_image(game->mlx_ptr, game->map.img_collectible);
	if (game->map.img_portal)
		mlx_destroy_image(game->mlx_ptr, game->map.img_portal);
	if (game->map.img_wall)
		mlx_destroy_image(game->mlx_ptr, game->map.img_wall);
	if (game->map.img_player)
		mlx_destroy_image(game->mlx_ptr, game->map.img_player);
	if (game->map.img_empty)
		mlx_destroy_image(game->mlx_ptr, game->map.img_empty);
	if (game->map.img_enemy)
		mlx_destroy_image(game->mlx_ptr, game->map.img_enemy);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_list(t_enemy *enemy)
{
	t_enemy	*tmp;

	while (enemy)
	{
		tmp = enemy->next;
		free(enemy);
		enemy = tmp;
	}
}
