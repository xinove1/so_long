/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:39:03 by nthomas-          #+#    #+#             */
/*   Updated: 2022/01/05 16:04:35 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_Vector2	add_vec2(t_Vector2 p1, t_Vector2 p2)
{
	t_Vector2	result;

	result.x = p1.x + p2.x;
	result.y = p1.y + p2.y;
	return (result);
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		printf("%s", game->map[i]);
		i++;
	}
	printf("Players: %d | Collectables: %d \n", game->players, game->collectables);
	printf("Map size: %d, %d \n", game->map_size.x, game->map_size.y);
	printf("win size: %d, %d \n", game->win_size.x, game->win_size.y);
}
