/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:57:37 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 04:54:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook_handler(int keycode, t_data *game)
{
	if (keycode == 65362 || keycode == 119)
		move_up(game);
	if (keycode == 65364 || keycode == 115)
		move_down(game);
	if (keycode == 65361 || keycode == 97)
		move_left(game);
	if (keycode == 65363 || keycode == 100)
		move_right(game);
	if (keycode == 65307)
		exit_and_free(game);
	if (keycode == 121)
		en_y(game);
	return (0);
}

void	update_player_position(t_data *game, int new_x, int new_y, char n)
{
	game->moves++;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = n;
}

void	en_y(t_data *game)
{
	get_player_position(game);
	if (game->map[game->player_y][game->player_x] == 'P')
		game->map[game->player_y][game->player_x] = 'Y';
	if (game->map[game->player_y][game->player_x] == 'L')
		game->map[game->player_y][game->player_x] = 'I';
	ft_display_map(game);
}

void	move_up(t_data *game)
{
	int	new_y;

	get_player_position(game);
	new_y = game->player_y - 1;
	if (new_y == game->height || game->map[new_y][game->player_x] == '1')
		return ;
	if (game->map[new_y][game->player_x] == 'C')
		game->collectible_count++;
	if (game->map[new_y][game->player_x] == 'E')
	{
		if (game->total_collectibles == game->collectible_count)
			exit_and_free(game);
		else
			return ;
	}
	if (game->map[game->player_y][game->player_x] == 'L')
		update_player_position(game, game->player_x, new_y, 'L');
	else
		update_player_position(game, game->player_x, new_y, 'P');
	ft_printf("Moves count : %d\n", game->moves);
	ft_display_map(game);
}

void	move_down(t_data *game)
{
	int	new_y;

	get_player_position(game);
	new_y = game->player_y + 1;
	if (new_y == game->height || game->map[new_y][game->player_x] == '1')
		return ;
	if (game->map[new_y][game->player_x] == 'C')
		game->collectible_count++;
	if (game->map[new_y][game->player_x] == 'E')
	{
		if (game->total_collectibles == game->collectible_count)
			exit_and_free(game);
		else
			return ;
	}
	if (game->map[game->player_y][game->player_x] == 'L')
		update_player_position(game, game->player_x, new_y, 'L');
	else
		update_player_position(game, game->player_x, new_y, 'P');
	ft_printf("Moves count : %d\n", game->moves);
	ft_display_map(game);
}
