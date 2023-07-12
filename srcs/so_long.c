/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:36:10 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 23:18:03 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	static t_data	game = {0};
	int				i;

	i = 0;
	if (argc < 2)
		return (write(1, "Usage -> ./so_long [path/to/map.ber]", 36));
	else if (argc == 2 && check_file_extension(argv[1]) == 0)
	{
		check_fd(argv);
		fill_map(argv[1], &game);
		if (!game.map)
			return (write(1, "Error\nUnable to fill the map\n", 29));
		print_map(game.map);
		start_game(&game);
	}
	else
		write(1, "File extension name error", 25);
	return (0);
}
