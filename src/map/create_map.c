/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:27:26 by grial             #+#    #+#             */
/*   Updated: 2024/09/09 18:49:23 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	create_map(char *path, t_game *game)
{
	if (!check_extension(path))
		return (0);
	if (!file_to_map(path, game))
		return (0);
	if (!check_walls(game))
	{
		ft_printf("Map must be surrounded by walls.\n");
		return (0);
	}
	if (!map_size(game))
		return (0);
	player_init(&game->player, game->map.map);
	if (!valid_path(game))
		return (0);
	return (1);
}
