/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:20:19 by grial             #+#    #+#             */
/*   Updated: 2024/09/08 15:10:59 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_extension(char *path)
{
	int	i;

	i = (ft_strlen(path) - 4);
	if (strcmp(path + i, ".ber") != 0)
	{
		ft_printf("Wrong file extension.\n");
		return (0);
	}
	return (1);
}
