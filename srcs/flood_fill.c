/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:44:11 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 03:33:52 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_visited(int **visited, t_data *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		free(visited[y]);
		y++;
	}
	free(visited);
}

int	**allocate_memory_visited(t_data *game)
{
	int	**visited;
	int	y;

	y = 0;
	visited = ft_calloc(game->height, sizeof(int *));
	while (y < game->height)
	{
		visited[y] = ft_calloc(game->width, sizeof(int));
		if (visited[y] == NULL)
		{
			free_visited(visited, game);
			handle_error(game, "Memory allocation error");
		}
		y++;
	}
	return (visited);
}

void	check_collectibles(t_data *game, int **visited)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C' && !visited[y][x])
			{
				free_visited(visited, game);
				handle_error(game, "Not all collectibles can be reached");
			}
			x++;
		}
		y++;
	}
}

void	check_reachability(t_data *game)
{
	int	**visited;

	visited = allocate_memory_visited(game);
	flood_fill(game->player_x, game->player_y, game, visited);
	check_collectibles(game, visited);
	free_visited(visited, game);
}

void	flood_fill(int x, int y, t_data *game, int **visited)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (visited[y][x] || game->map[y][x] == '1' || game->map[y][x] == 'E')
		return ;
	visited[y][x] = 1;
	flood_fill(x - 1, y, game, visited);
	flood_fill(x + 1, y, game, visited);
	flood_fill(x, y - 1, game, visited);
	flood_fill(x, y + 1, game, visited);
}
