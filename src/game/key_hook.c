/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:07:29 by grial             #+#    #+#             */
/*   Updated: 2024/09/04 18:35:08 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	key_hook(int key, t_game *game)
{
	if (key == ESCAPE)
		destroy_game(game);
	else if (key == LEFT || key == UP || key == RIGHT || key == DOWN)
		move_player(key, game);
	return (1);
}
