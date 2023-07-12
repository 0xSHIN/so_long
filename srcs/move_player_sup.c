/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_sup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:34:20 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 04:54:37 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *game)
{
	int	new_x;

	get_player_position(game);
	new_x = game->player_x - 1;
	if (new_x == game->width || game->map[game->player_y][new_x] == '1')
		return ;
	if (game->map[game->player_y][new_x] == 'C')
		game->collectible_count++;
	if (game->map[game->player_y][new_x] == 'E')
	{
		if (game->total_collectibles == game->collectible_count)
			exit_and_free(game);
		else
			return ;
	}
	update_player_position(game, new_x, game->player_y, 'L');
	ft_printf("Moves count : %d\n", game->moves);
	ft_display_map(game);
}

void	move_right(t_data *game)
{
	int	new_x;

	get_player_position(game);
	new_x = game->player_x + 1;
	if (new_x == game->width || game->map[game->player_y][new_x] == '1')
		return ;
	if (game->map[game->player_y][new_x] == 'C')
		game->collectible_count++;
	if (game->map[game->player_y][new_x] == 'E')
	{
		if (game->total_collectibles == game->collectible_count)
			exit_and_free(game);
		else
			return ;
	}
	update_player_position(game, new_x, game->player_y, 'P');
	ft_printf("Moves count : %d\n", game->moves);
	ft_display_map(game);
}
