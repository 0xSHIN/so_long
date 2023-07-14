/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:56:51 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/13 01:11:45 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_row(char *argv, t_data *game)
{
	char	*str;
	int		fd;
	int		row;

	row = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		row++;
	}
	free(str);
	close(fd);
	return (row);
}

void	del_backslash_n(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '\n' || game->map[i][j] == ' ')
				game->map[i][j] = '\0';
			j++;
		}
		i++;
	}
	game->width = ft_strlen(game->map[0]);
}

char	**allocate_final_map(t_data *game, char **final_map, int i)
{
	int		j;

	j = -1;
	final_map[i] = ft_calloc((ft_strlen(game->map[i]) + 1), sizeof(char));
	if (!final_map[i])
	{
		ft_free_map(final_map);
		exit_and_free(game);
		return (NULL);
	}
	while (game->map[i][++j])
		final_map[i][j] = game->map[i][j];
	final_map[i][j] = 0;
	return (final_map);
}

char	**del_null_char(t_data *game)
{
	char	**final_map;
	int		i;
	int		size;
	int		tmp;

	i = 0;
	size = ft_strlen(game->map[i]);
	final_map = ft_calloc((game->height + 1), sizeof(char *));
	if (!final_map)
		return (NULL);
	while (game->map[i])
	{
		tmp = ft_strlen(game->map[i]);
		if (tmp > 0 && tmp == size)
			final_map = allocate_final_map(game, final_map, i);
		else
		{
			ft_free_map(final_map);
			handle_error(game, "Incorrect game map !");
		}
		i++;
	}
	final_map[i] = NULL;
	ft_free_map(game->map);
	return (final_map);
}

void	fill_map(char *argv, t_data *game)
{
	char	*str;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return ;
	game->height = count_map_row(argv, game);
	game->map = ft_calloc((game->height + 1), sizeof(char *));
	if (!game->map)
		return ;
	i = -1;
	game->map[++i] = get_next_line(fd);
	while (game->map[i++])
		game->map[i] = get_next_line(fd);
	close(fd);
	del_backslash_n(game);
	game->map = del_null_char(game);
}
