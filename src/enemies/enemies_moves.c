/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:29:10 by grial             #+#    #+#             */
/*   Updated: 2024/09/04 19:37:02 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	update_enemy_position(t_game *game)
{
	int		tmp_x;
	int		tmp_y;
	t_enemy	*tmp_enemy;

	tmp_enemy = game->enemy;
	while (tmp_enemy)
	{
		tmp_x = tmp_enemy->pos_x;
		tmp_y = tmp_enemy->pos_y;
		if (tmp_enemy->number % 2 == 0)
			horizontal_enemy(game, tmp_enemy);
		else
			vertical_enemy(game, tmp_enemy);
		game->map.map[tmp_y][tmp_x] = '0';
		if (game->map.map[tmp_enemy->pos_y][tmp_enemy->pos_x] == 'P')
		{
			ft_printf("You Lost!\n");
			destroy_game(game);
		}
		game->map.map[tmp_enemy->pos_y][tmp_enemy->pos_x] = 'A';
		tmp_enemy = tmp_enemy->next;
	}
}

void	horizontal_enemy(t_game *game, t_enemy *enemy)
{
	if ((game->map.map[enemy->pos_y][enemy->pos_x + 1] == '0' || 
		game->map.map[enemy->pos_y][enemy->pos_x + 1] == 'P') && 
		enemy->direction == 0)
		enemy->pos_x++;
	else
		enemy->direction = 1;
	if ((game->map.map[enemy->pos_y][enemy->pos_x - 1] == '0' || 
		game->map.map[enemy->pos_y][enemy->pos_x - 1] == 'P') && 
		enemy->direction == 1)
		enemy->pos_x--;
	else
		enemy->direction = 0;
}

void	vertical_enemy(t_game *game, t_enemy *enemy)
{
	if ((game->map.map[enemy->pos_y + 1][enemy->pos_x] == '0' || 
		game->map.map[enemy->pos_y + 1][enemy->pos_x] == 'P') && 
		enemy->direction == 0)
		enemy->pos_y++;
	else
		enemy->direction = 1;
	if ((game->map.map[enemy->pos_y - 1][enemy->pos_x] == '0' || 
		game->map.map[enemy->pos_y - 1][enemy->pos_x] == 'P') && 
		enemy->direction == 1)
		enemy->pos_y--;
	else
		enemy->direction = 0;
}
