/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_sup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:57:10 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/11 20:02:51 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular_map(t_data *game)
{
	int		i;
	int		first_row_length;
	int		row_length;

	i = 1;
	first_row_length = ft_strlen(game->map[0]);
	while (i < game->height)
	{
		row_length = ft_strlen(game->map[i]);
		if (first_row_length != row_length)
			return (0);
		i++;
	}
	return (1);
}

int	verify_map_characters(t_data *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((game->map[i][j] != '1') && (game->map[i][j] != '0')
					&& (game->map[i][j] != 'C') && (game->map[i][j]) != 'P'
					&& (game->map[i][j] != 'E') && (game->map[i][j] != 'Y')
					&& (game->map[i][j] != 'L') && (game->map[i][j] != 'I'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
