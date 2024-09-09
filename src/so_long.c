/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:13:15 by grial             #+#    #+#             */
/*   Updated: 2024/09/08 15:41:30 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
	{
		ft_printf("Must introduce a map.  <./so_long map/map_name.ber>\n");
		return (0);
	}
	game = init_values(game);
	if (!game)
	{
		ft_printf("Failed to allocate memory for game.\n");
		return (0);
	}
	if (!game)
	{
		ft_printf("Failed to allocate memory for game.\n");
		return (0);
	}
	if (!create_map(argv[1], game))
	{
		destroy_game(game);
		return (0);
	}
	init_game(game);
}

t_game	*init_values(t_game *game)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->mlx_ptr = NULL;
	game->mlx_window = NULL;
	game->n_frames = 0;
	game->map.img_collectible = NULL;
	game->map.img_enemy = NULL;
	game->map.img_player = NULL;
	game->map.img_portal = NULL;
	game->map.img_wall = NULL;
	game->map.img_empty = NULL;
	game->map.map = NULL;
	game->enemy = NULL;
	return (game);
}
