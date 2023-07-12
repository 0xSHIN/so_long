/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:57:27 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 04:19:48 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_single_img(void **img_ptr, t_data *game, char *path)
{
	*img_ptr = mlx_xpm_file_to_image(game->mlx, path,
			&game->size_ximg, &game->size_yimg);
	if (!*img_ptr)
		handle_error(game, "Image not initialized");
}

void	init_img(t_data *game)
{
	init_single_img((void **)&game->player, game, "./sprites/moto.xpm");
	init_single_img((void **)&game->player_left, game,
		"./sprites/moto_left.xpm");
	init_single_img((void **)&game->en_y, game, "./sprites/en_y.xpm");
	init_single_img((void **)&game->en_y_left, game, "./sprites/en_y_left.xpm");
	init_single_img((void **)&game->exit, game, "./sprites/exit.xpm");
	init_single_img((void **)&game->collectible, game, "./sprites/money.xpm");
	init_single_img((void **)&game->floor, game, "./sprites/floor.xpm");
	init_single_img((void **)&game->wall, game, "./sprites/wall.xpm");
}

void	ft_display_map_choice(t_data *game, size_t i, size_t j)
{
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->player, (j * 64), (i * 64));
	if (game->map[i][j] == 'L')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->player_left, (j * 64), (i * 64));
	if (game->map[i][j] == 'I')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->en_y_left, (j * 64), (i * 64));
	if (game->map[i][j] == 'Y')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->en_y, (j * 64), (i * 64));
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->collectible, (j * 64), (i * 64));
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->exit, (j * 64), (i * 64));
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->floor, (j * 64), (i * 64));
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->wall, (j * 64), (i * 64));
}

void	ft_display_map(t_data *game)
{
	size_t	i;
	size_t	j;
	char	*moves;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			moves = ft_itoa(game->moves);
			mlx_string_put(game->mlx, game->mlx_win, 28, 32, 0xffffffff, moves);
			free(moves);
			ft_display_map_choice(game, i, j++);
		}
		i++;
	}
}

int	start_game(t_data *game)
{
	game->mlx = mlx_init();
	init_img(game);
	count_map_length(game);
	get_player_position(game);
	validate_map(game);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	ft_display_map(game);
	mlx_hook(game->mlx_win, 17, (1L << 17), exit_and_free, game);
	mlx_key_hook(game->mlx_win, keyhook_handler, game);
	mlx_loop(game->mlx);
	return (0);
}
