/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:20:19 by grial             #+#    #+#             */
/*   Updated: 2024/09/08 15:04:33 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_walls(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (game->map.map[y])
		y++;
	x = ft_strlen(game->map.map[0]);
	while (i < x)
	{
		if ((game->map.map[0][i] != '1' || game->map.map[y - 1][i] != '1'))
			return (0);
		i++;
	}
	i = 0;
	while (i < y)
	{
		if ((game->map.map[i][0] != '1' || game->map.map[i][x - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}
