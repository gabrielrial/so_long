/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:26:56 by grial             #+#    #+#             */
/*   Updated: 2024/09/01 18:27:13 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	collect_exit(t_game *game)
{
	char	c;

	c = game->map.map[game->player.pos_y][game->player.pos_x];
	if ((c == 'E') && (game->counter.collectibles == 0))
		endgame (game);
}
