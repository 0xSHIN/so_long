/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:55:21 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 04:54:37 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_error(t_data *game, char *error_message)
{
	ft_printf("\nError\n%s\n", error_message);
	exit_and_free(game);
}

void	check_map_characters(t_data *game)
{
	if (!verify_map_characters(game))
		handle_error(game, "Incorrect map character in given map.");
}

void	check_collectibles_and_exits(t_data *game)
{
	if (!count_collectibles_and_exits(game))
		handle_error(game, "Incorrect collectible, exit or player count !");
}

void	check_map_walls(t_data *game)
{
	if (!check_map_surrounded_by_walls(game))
		handle_error(game, "Map not enclosed by walls");
}

void	check_map_shape(t_data *game)
{
	if (!check_rectangular_map(game))
		handle_error(game, "Map not rectangular");
}
