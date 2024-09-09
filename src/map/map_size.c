/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:20:19 by grial             #+#    #+#             */
/*   Updated: 2024/09/08 15:08:43 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	map_size(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map.map[y])
		y++;
	while (game->map.map[0][x])
		x++;
	if (x == y - 1)
	{
		ft_printf("Map must be rectangular\n");
		return (0);
	}
	if (x > 80 || y > 40)
	{
		ft_printf("The map must be no larger than 80 x 44\n");
		return (0);
	}
	game->map.size_x = x * SIZE;
	game->map.size_y = (y + 1) * SIZE; 
	return (1);
}
