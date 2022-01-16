/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:38:36 by nthomas-          #+#    #+#             */
/*   Updated: 2022/01/16 12:16:26 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parser_error_handler(int error, t_game *game, void *ptr)
{
	printf("Error\n");
	if (error == 1)
		printf("The map dosen't have a rectangular shape.\n");
	else if (error == 2)
		printf("Walls don't cover all the outer map.\n");
	else if (error == 3)
		printf("Empty map file.\n");
	else if (error == 4)
		perror("");
	else if (error == 5)
		printf("Map must have at least one exit, one collectible, "
			"and one starting position.\n");
	else if (error == 6)
		ft_putstr_fd("Can't create a game without a map.", 2);
	clean(game, ptr);
	exit(1);
}
