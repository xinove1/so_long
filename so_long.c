/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:38:45 by nthomas-          #+#    #+#             */
/*   Updated: 2022/01/16 12:15:05 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, const char *argv[])
{
	t_game	game;

	init_values(&game);
	if (argc < 2)
		parser_error_handler(6, &game, NULL);
	else if (argc > 2)
		parser_error_handler(7, &game, NULL);
	parse_map(&game, (char *)argv[1]);
	print_credits();
	init_mlx(&game);
	mlx_loop(game.mlx_ptr);
}

int	draw(t_game *g)
{
	int		y;
	int		x;
	char	*moves;

	y = 0;
	while (y < g->map_size.y)
	{
		x = 0;
		while (x < g->map_size.x)
		{
			draw_tile(g, x, y);
			x++;
		}
		y++;
	}
	moves = ft_itoa(g->moves);
	mlx_string_put(g->mlx_ptr, g->win, 3, 11, 255, moves);
	free(moves);
	return (0);
}

void	draw_tile(t_game *g, int i, int j)
{
	int	x;
	int	y;

	x = TILE_SIZE * i;
	y = TILE_SIZE * j;
	if (g->map[j][i] == '0')
		mlx_put_image_to_window(g->mlx_ptr, g->win, g->tiles[3], x, y);
	else if (g->map[j][i] == '1')
		mlx_put_image_to_window(g->mlx_ptr, g->win, g->tiles[4], x, y);
	else if (g->map[j][i] == 'P' && g->player_state < 0)
		mlx_put_image_to_window(g->mlx_ptr, g->win, g->tiles[0], x, y);
	else if (g->map[j][i] == 'P' && g->player_state > 0)
		mlx_put_image_to_window(g->mlx_ptr, g->win, g->tiles[1], x, y);
	else if (g->map[j][i] == 'E')
		mlx_put_image_to_window(g->mlx_ptr, g->win, g->tiles[5], x, y);
	else if (g->map[j][i] == 'C')
		mlx_put_image_to_window(g->mlx_ptr, g->win, g->tiles[2], x, y);
}

void	init_mlx(t_game	*game)
{
	game->win_size.x = TILE_SIZE * game->map_size.x;
	game->win_size.y = TILE_SIZE * game->map_size.y;
	game->mlx_ptr = mlx_init();
	game->win = mlx_new_window(game->mlx_ptr,
			game->win_size.x,
			game->win_size.y,
			"So_long");
	mlx_key_hook(game->win, handle_keys, game);
	mlx_expose_hook(game->win, draw, game);
	mlx_hook(game->win, 17, 0L, exit_game, game);
	init_images(game);
}

void	init_images(t_game	*g)
{
	int	x;
	int	y;

	g->tiles[0] = mlx_xpm_file_to_image(g->mlx_ptr,
			"resources/p_01.xpm", &x, &y);
	g->tiles[1] = mlx_xpm_file_to_image(g->mlx_ptr,
			"resources/p_02.xpm", &x, &y);
	g->tiles[2] = mlx_xpm_file_to_image(g->mlx_ptr,
			"resources/collect.xpm", &x, &y);
	g->tiles[3] = mlx_xpm_file_to_image(g->mlx_ptr,
			"resources/tile.xpm", &x, &y);
	g->tiles[4] = mlx_xpm_file_to_image(g->mlx_ptr,
			"resources/wall.xpm", &x, &y);
	g->tiles[5] = mlx_xpm_file_to_image(g->mlx_ptr,
			"resources/exit.xpm", &x, &y);
	g->tiles[6] = NULL;
}
