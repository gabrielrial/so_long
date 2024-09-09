/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:25:35 by grial             #+#    #+#             */
/*   Updated: 2024/09/01 18:25:35 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	player_init(t_player *player, char **map)
{
	int	x;
	int	y;

	y = 1;
	while (map)
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player->pos_x = x;
				player->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
