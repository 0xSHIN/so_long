/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:30:49 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 03:34:05 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectibles_and_exits(t_data *game)
{
	int	player_count;
	int	y;
	int	x;

	player_count = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			update_counts(game, y, x, &player_count);
			x++;
		}
		y++;
	}
	return (validate_counts(game, player_count));
}

int	check_map_surrounded_by_walls(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			return (0);
		x++;
	}
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	validate_map(t_data *game)
{
	check_collectibles_and_exits(game);
	check_map_walls(game);
	check_map_shape(game);
	check_reachability(game);
	check_map_characters(game);
}

void	update_counts(t_data *game, int y, int x, int *player_count)
{
	if (game->map[y][x] == 'C')
		game->total_collectibles++;
	else if (game->map[y][x] == 'E')
		game->total_exits++;
	else if (game->map[y][x] == 'P')
		(*player_count)++;
}

int	validate_counts(t_data *game, int player_count)
{
	if (game->total_exits != 1
		|| game->total_collectibles == 0 || player_count > 1)
		return (0);
	else
		return (1);
}
