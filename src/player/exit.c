/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:46:36 by grial             #+#    #+#             */
/*   Updated: 2024/09/01 18:59:11 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	endgame(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->counter.moves);
	mlx_clear_window(game->mlx_ptr, game->mlx_window);
	mlx_string_put(game->mlx_ptr, game->mlx_window, 
		game->map.size_x / 2, game->map.size_y / 2, 500, "Movimientos:");
	mlx_string_put(game->mlx_ptr, game->mlx_window, 
		(game->map.size_x / 2 + 75), game->map.size_y / 2, 500, 
		ft_itoa(game->counter.moves));
	free(moves);
	destroy_game(game);
}
