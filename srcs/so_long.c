/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:36:10 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 04:54:53 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_data *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->en_y = NULL;
	game->player_left = NULL;
	game->player = NULL;
	game->en_y_left = NULL;
	game->collectible = NULL;
	game->exit = NULL;
	game->floor = NULL;
	game->wall = NULL;
	game->moves = 0;
	game->collectible_count = 0;
	game->total_collectibles = 0;
	game->total_exits = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->width = 0;
	game->height = 0;
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	check_fd(char **argv)
{
	char	buffer[1];
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, buffer, 1) == -1)
	{
		write(1, "Error\nUnable to parse file\n", 28);
		if (fd >= 0)
			close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*game;
	int		i;

	i = 0;
	if (argc < 2)
		return (write(1, "Usage -> ./so_long [path/to/map.ber]", 36));
	else if (argc == 2 && check_file_extension(argv[1]) == 0)
	{
		check_fd(argv);
		game = ft_calloc(1, sizeof(t_data));
		if (!game)
			return (EXIT_FAILURE);
		init_game(game);
		fill_map(argv[1], game);
		if (!game->map)
		{
			write(1, "Error\nUnable to fill the map\n", 29);
			return (free(game), EXIT_FAILURE);
		}
		print_map(game->map);
		start_game(game);
	}
	else
		write(1, "File extension name error", 25);
	return (0);
}
