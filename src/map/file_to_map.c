/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:23:07 by grial             #+#    #+#             */
/*   Updated: 2024/09/04 19:05:02 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	file_to_map(char *path, t_game *game)
{
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File does not exist.\n");
		return (0);
	}
	str = file_to_string(fd);
	close(fd);
	if (!str)
		return (0);
	if (!count_elements(&game->counter, str))
	{
		free(str);
		return (0);
	}
	else
		game->map.map = load_map_to_array(str);
	free(str);
	str = NULL;
	return (1);
}

char	*file_to_string(int fd)
{
	char	*temp;
	char	*line;
	char	*new_temp;

	temp = ft_strdup_gnl("");
	if (!temp)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new_temp = ft_strjoin_gnl(temp, line);
		free(temp);
		free(line);
		temp = new_temp;
		if (!temp)
			return (0);
	}
	return (temp);
}

char	**load_map_to_array(char *str)
{
	char	**map;

	map = ft_split(str, '\n');
	return (map);
}
