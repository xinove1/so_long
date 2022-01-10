/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:38:54 by nthomas-          #+#    #+#             */
/*   Updated: 2022/01/07 12:00:07 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game, char *map_path)
{
	game->map_size = get_map_size(map_path, game);
	get_map(game, map_path);
	parse_inner_map(game);
	parse_players_position(game);
	check_walls(game);
}

void	parse_inner_map(t_game *game)
{
	int	x;
	int	y;
	int	exits;

	x = 1;
	y = 1;
	exits = 0;
	// test if this is really the inner map
	while (y < game->map_size.y - 1)
	{
		x = 1;
		while (x < game->map_size.x - 1)
		{
			if (game->map[y][x] == 'C')
				game->collectables++;
			else if (game->map[y][x] == 'P')
				game->players++;
			else if (game->map[y][x] == 'E')
				exits++;
			x++;
		}
		y++;
	}
	if (game->collectables == 0 || game->players == 0 || exits == 0)
		parser_error_handler(5, game, NULL);
}

void	check_walls(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_size.y)
		if (game->map[i][0] != '1')
			parser_error_handler(2, game, NULL);
	i = -1;
	while (++i < game->map_size.y)
		if (game->map[i][game->map_size.x - 1] != '1')
			parser_error_handler(2, game, NULL);
	i = -1;
	while (++i < game->map_size.x - 1)
		if (game->map[0][i] != '1')
			parser_error_handler(2, game, NULL);
	i = -1;
	while (++i < game->map_size.x - 1)
		if (game->map[game->map_size.y - 1][i] != '1')
			parser_error_handler(2, game, NULL);
}

void	parse_players_position(t_game *game)
{
	int	x;
	int	y;
	int	i;

	// SUS
	game->players_p = malloc(sizeof(t_Vector2 *) * game->players);
	x = 1;
	y = 1;
	i = 0;
	while (y < game->map_size.y - 1)
	{
		x = 1;
		while (x < game->map_size.x - 1)
		{
			if (game->map[y][x] == 'P')
			{
				game->players_p[i].x = x;
				game->players_p[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	get_map(t_game *game, char *path)
{
	int			fd;
	char		*line;
	int			i;

	game->map = malloc(sizeof(char **) * (game->map_size.y + 1));
	game->map[game->map_size.y] = NULL;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
}

t_Vector2	get_map_size(char *path, t_game *game)
{
	int			fd;
	t_Vector2	size;
	char		*line;

	fd = open(path, O_RDONLY);
	// TODO: is this how u verify open?
	if (fd <= 0)
		parser_error_handler(4, game, NULL);
	line = get_next_line(fd);
	if (!line)
		parser_error_handler(3, game, line);
	size.x = ft_strlen(line);
	size.y = 0;
	while (line)
	{
		if ((int)ft_strlen(line) != size.x)
			parser_error_handler(1, game, line);
		size.y++;
		free(line);
		line = get_next_line(fd);
	}
	size.x--;
	return (size);
}
