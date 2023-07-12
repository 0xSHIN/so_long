/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:59:40 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 04:18:44 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_check(t_data *game)
{
	if (game == NULL)
		handle_error(game, "game is NULL");
	if (game->map == NULL)
		handle_error(game, "game->map is NULL");
}

int	find_player(t_data *game, int y, int x)
{
	if (game->map[y][x] == 'P' || game->map[y][x] == 'L'
		|| game->map[y][x] == 'I' || game->map[y][x] == 'Y')
	{
		game->player_y = y;
		game->player_x = x;
		return (1);
	}
	return (0);
}

void	get_player_position(t_data *game)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	error_check(game);
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (find_player(game, y, x))
				return ;
			x++;
		}
		y++;
	}
	handle_error(game, "Player not found on map");
}
