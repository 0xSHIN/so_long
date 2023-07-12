/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_sup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:43:00 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 04:21:59 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map_length(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (game == NULL)
		handle_error(game, "game is NULL\n");
	if (game->map)
	{
		while (game->map[y])
		{
			x = 0;
			while (game->map[y][x])
				x++;
			y++;
		}
	}
	game->width = x;
}
