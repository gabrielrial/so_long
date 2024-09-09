/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:32:13 by grial             #+#    #+#             */
/*   Updated: 2024/09/08 15:42:25 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "so_utils.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

t_game	*init_values(t_game *game);
int		file_to_map(char *path, t_game *game);
char	*file_to_string(int fd);
char	**load_map_to_array(char *str);
int		check_walls(t_game *game);
void	init_game(t_game *game);
void	player_init(t_player *player, char **map);
int		move_player(int key, t_game *game);
int		valid_move(t_game *game, int key);
void	load_images(t_game *game);
int		count_elements(t_counter *counter, char *str);
void	collect_coin(t_game *game);
int		map_size(t_game *game);
int		key_hook(int key, t_game *game);
void	free_img(t_game *game);

// ANIMATIONS
int		animations(t_game *game);
int		load_animation(t_game *game, char *player_path, char *enemy_path);
void	animation_each_enemy(t_game *game);
void	move_animation(t_game *game);

// DRAW MAP
void	draw_windows(t_game *game);
void	draw_map(t_game *game);
void	put_score(t_game *game);
void	*hook_img(t_game *game, char c);

// ENEMIES
int		create_enemy(t_game *game);
t_enemy	*sl_lstlast(t_enemy *lst);
void	find_position(char **map, t_enemy *enemy, int count);
void	update_enemy_position(t_game *game);
void	horizontal_enemy(t_game *game, t_enemy *enemy);
void	vertical_enemy(t_game *game, t_enemy *enemy);
void	sl_lstadd_back(t_enemy **lst, t_enemy *new);

// MAP
int		check_extension(char *path);
int		create_map(char *path, t_game *game);
int		valid_path(t_game *game);
char	**copy_map(t_game *game);
int		check_map(char **map);
void	flood_fill(t_game *game, char **map_copied, int x, int y);
void	new_counter(t_counter *counter);
int		check_elements(t_counter *counter, char *str);
int		count_elements(t_counter *counter, char *str);

// END GAME
void	endgame(t_game *game);
int		destroy_game(t_game *game);

// DESTROY GAME
void	free_map(char **map);

#endif