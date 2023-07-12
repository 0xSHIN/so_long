/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:26:47 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 03:01:16 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extension(char *filename)
{
	char	*extension;
	int		filename_size;
	int		i;

	i = 0;
	extension = ".ber";
	filename_size = ft_strlen(filename);
	if (filename_size < 4)
		return (1);
	filename_size -= 4;
	while (i < 4)
	{
		if (extension[i] != filename[filename_size + i])
			return (1);
		i++;
	}
	return (0);
}

void	mlx_destroy_image_if_exists(void *mlx, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

int	exit_and_free(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	mlx_destroy_image_if_exists(game->mlx, game->player);
	mlx_destroy_image_if_exists(game->mlx, game->exit);
	mlx_destroy_image_if_exists(game->mlx, game->collectible);
	mlx_destroy_image_if_exists(game->mlx, game->floor);
	mlx_destroy_image_if_exists(game->mlx, game->player_left);
	mlx_destroy_image_if_exists(game->mlx, game->en_y);
	mlx_destroy_image_if_exists(game->mlx, game->en_y_left);
	mlx_destroy_image_if_exists(game->mlx, game->wall);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(EXIT_SUCCESS);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}
