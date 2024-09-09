/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:54:32 by grial             #+#    #+#             */
/*   Updated: 2024/09/01 18:48:39 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_UTILS_H
# define SO_UTILS_H

# define ESCAPE 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

# define SIZE 24

typedef struct s_map
{
	char	**map;
	int		size_x;
	int		size_y;
	void	*img_wall;
	void	*img_enemy;
	void	*img_empty;
	void	*img_portal;
	void	*img_player;
	void	*img_collectible;
}	t_map;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	moving;
}	t_player;

typedef struct s_enemy
{
	int					direction;
	int					number;
	int					pos_x;
	int					pos_y;
	struct s_enemy		*next;
}	t_enemy;

typedef struct s_counter
{
	int	exit;
	int	enemy;
	int	moves;
	int	player;
	int	collectibles;
}	t_counter;

typedef struct s_game
{
	void				*mlx_ptr;
	void				*mlx_window;
	int					n_frames;
	t_map				map;
	t_player			player;
	t_enemy				*enemy;
	t_counter			counter;
}	t_game;

#endif