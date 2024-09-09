/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:28:38 by grial             #+#    #+#             */
/*   Updated: 2024/09/01 18:39:02 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_enemy	*sl_lstnew(int content)
{
	t_enemy	*node;

	node = malloc(sizeof(t_enemy));
	if (!node)
		return (NULL);
	node->direction = 0;
	node->number = content;
	node->pos_x = 0;
	node->pos_y = 0;
	node->next = NULL;
	return (node);
}

int	create_enemy(t_game *game)
{
	int		i;
	t_enemy	*new_enemy;

	game->enemy = NULL;
	i = 1;
	while (i <= game->counter.enemy)
	{
		new_enemy = sl_lstnew(i);
		find_position(game->map.map, new_enemy, i);
		sl_lstadd_back(&(game->enemy), new_enemy);
		i++;
	}
	return (1);
}

void	find_position(char **map, t_enemy *enemy, int count)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'A')
				count--;
			if (count == 0)
			{
				enemy->pos_y = y;
				enemy->pos_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}
