/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:38:57 by nthomas-          #+#    #+#             */
/*   Updated: 2022/01/16 11:19:11 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# define TILE_SIZE 16
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_ESC 65307

typedef struct s_Vector2
{
	int		x;
	int		y;
}			t_Vector2;

typedef struct s_game
{
	char		**map;
	t_Vector2	map_size;
	int			collectables;
	int			collected;
	int			players;
	t_Vector2	*players_p;
	int			moves;
	void		*mlx_ptr;
	void		*win;
	t_Vector2	win_size;
	void		*tiles[7];
	int			state;
}				t_game;

void		clean_map(char **map);
void		clean(t_game *game, void *ptr);
void		parse_map(t_game *game, char *map_path);
t_Vector2	get_map_size(char *path, t_game *game);
void		get_map(t_game *game, char *path);
void		check_walls(t_game *game);
void		parse_players_position(t_game *game);
void		move(t_game *game, t_Vector2 dir);
void		print_map(t_game *game);
t_Vector2	add_vec2(t_Vector2 p1, t_Vector2 p2);
void		parser_error_handler(int error, t_game *game, void *ptr);
void		change_map(t_game *game, t_Vector2 target, char c);
void		change_player_pos(t_game *game, int i, t_Vector2 dir);
int			draw(t_game *game);
int			handle_keys(int code, t_game *game);
void		init_images(t_game	*game);
int			exit_game(t_game *game);
void		parse_inner_map(t_game *game);
void		draw_tile(t_game *g, int x, int y);
void		init_mlx(t_game	*game);
void		init_values(t_game *game);
void		print_credits(void);

#endif
