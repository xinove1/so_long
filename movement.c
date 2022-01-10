/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:38:48 by nthomas-          #+#    #+#             */
/*   Updated: 2022/01/05 22:49:57 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, t_Vector2 dir)
{
	char		new_pos;
	int			i;
	t_Vector2	*current_pos;

	current_pos = game->players_p;
	i = 0;
	while (i < game->players)
	{
		new_pos = game->map[current_pos[i].y + dir.y][current_pos[i].x + dir.x];
		if (new_pos == '0')
			change_player_pos(game, i, dir);
		else if (new_pos == 'E' && game->collected == game->collectables)
			printf("Game Won\n");
		else if (new_pos == 'C')
		{
			change_player_pos(game, i, dir);
			game->collected++;
		}
		i++;
	}
	game->moves++;
	printf("%d\n", game->moves);
	new_pos++;
	draw(game);
}

void	change_player_pos(t_game *game, int i, t_Vector2 dir)
{
	change_map(game, add_vec2(game->players_p[i], dir), 'P');
	change_map(game, game->players_p[i], '0');
	game->players_p[i] = add_vec2(game->players_p[i], dir);
}

void	change_map(t_game *game, t_Vector2 target, char c)
{
	game->map[target.y][target.x] = c;
}
