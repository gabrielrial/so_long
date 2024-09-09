/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:31:43 by grial             #+#    #+#             */
/*   Updated: 2024/09/08 14:24:22 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	new_counter(t_counter *counter)
{
	counter->exit = 0;
	counter->enemy = 0;
	counter->moves = 0;
	counter->player = 0;
	counter->collectibles = 0;
}

int	check_elements(t_counter *counter, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'E')
			counter->exit++;
		else if (str[i] == 'A')
			counter->enemy++;
		else if (str[i] == 'C')
			counter->collectibles++;
		else if (str[i] == 'P')
			counter->player++;
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n')
		{
			ft_printf("Wrong characters on map.\n");
			return (0);
		}
		i++;
	}
	if (counter->collectibles < 1 || counter->exit != 1 || counter->player != 1)
		return (0);
	return (1);
}

int	count_elements(t_counter *counter, char *str)
{
	new_counter(counter);
	if (!check_elements(counter, str))
	{
		ft_printf("At least: 1 Player(P), 1 Coin(C) and 1 Exit(E).");
		return (0);
	}
	return (1);
}
