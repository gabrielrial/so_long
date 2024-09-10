/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:09:59 by grial             #+#    #+#             */
/*   Updated: 2024/09/10 14:47:31 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	valid_path(t_game *game)
{
	int		y;
	char	**map_copied;

	y = 0;
	map_copied = copy_map(game);
	if (!map_copied)
		return (0);
	flood_fill(game, map_copied, game->player.pos_y, game->player.pos_x);
	if (!check_map(map_copied))
	{
		ft_printf("Map does not have a valid path.\n");
		free_map(map_copied);
		return (0);
	}
	free_map(map_copied);
	return (1);
}

int	check_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '.' && map[y][x] != '1' && 
				map[y][x] != 'A' && map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char	**copy_map(t_game *game)
{
	int		y;
	char	**map_copied;

	y = 0;
	while (game->map.map[y])
		y++;
	map_copied = (char **)malloc(sizeof(char *) * (y + 1));
	if (!map_copied)
		return (0);
	y = 0;
	while (game->map.map[y])
	{
		map_copied[y] = ft_strdup(game->map.map[y]);
		if (!map_copied[y])
		{
			while (y > 0)
				free(map_copied[--y]);
			free(map_copied);
			return (0);
		}
		y++;
	}
	map_copied[y] = NULL;
	return (map_copied);
}

void	flood_fill(t_game *game, char **map_copied, int y, int x)
{
	if (x <= 0 || y <= 0 || x > game->map.size_x / SIZE || 
		y > (game->map.size_y - 1) / SIZE || game->map.map[y][x] == '1' || 
		game->map.map[y][x] == 'A')
		return ;
	map_copied[y][x] = '.';
	if (map_copied[y][x + 1] != '.')
		flood_fill(game, map_copied, y, x + 1);
	if (map_copied[y][x - 1] != '.')
		flood_fill(game, map_copied, y, x - 1);
	if (map_copied[y + 1][x] != '.')
		flood_fill(game, map_copied, y + 1, x);
	if (map_copied[y - 1][x] != '.')
		flood_fill(game, map_copied, y - 1, x);
}
