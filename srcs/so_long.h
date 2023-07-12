/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:57:45 by alyildiz          #+#    #+#             */
/*   Updated: 2023/07/12 05:02:29 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;

	char	**map;
	void	*player;
	void	*player_left;
	void	*collectible;
	void	*exit;
	void	*floor;
	void	*en_y;
	void	*en_y_left;
	void	*wall;

	int		total_collectibles;
	int		total_exits;
	int		collectible_count;
	int		moves;
	int		row;

	int		player_x;
	int		player_y;
	int		size_yimg;
	int		size_ximg;

	int		width;
	int		height;

}	t_data;

// main functions
int			start_game(t_data *game);
int			main(int argc, char **argv);

// utils 
char		*ft_itoa(int n);
int			check_file_extension(char *filename);
int			ft_strlen(char *str);
int			ft_strchr(const char *str, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*get_current_line(char *stash);
char		*add_left_to_stash(char *stash);
char		*get_next_line(int fd);
void		*ft_calloc(size_t count, size_t size);

// exiting
void		destroy_mlx(t_data *game);
int			exit_and_free(t_data *game);
void		handle_error(t_data *game, char *error_message);
void		ft_free_map(char **map);

// keyhook
int			keyhook_handler(int keycode, t_data *game);
void		move_up(t_data *game);
void		move_down(t_data *game);
void		move_right(t_data *game);
void		move_left(t_data *game);
void		en_y(t_data *game);

// collectible count
void		update_counts(t_data *game, int y, int x, int *player_count);
int			validate_counts(t_data *game, int player_count);
int			count_collectibles_and_exits(t_data *game);

// map parsing
void		count_map_length(t_data *game);
void		fill_map(char *argv, t_data *game);
int			count_map_row(char *argv, t_data *game);
void		del_backslash_n(t_data *game);
void		get_player_position(t_data *game);
void		ft_display_map(t_data *game);
void		update_player_position(t_data *game, int new_x, int new_y, char n);
int			find_player(t_data *game, int y, int x);

// map validity
void		check_collectibles_and_exits(t_data *game);
int			check_map_surrounded_by_walls(t_data *game);
int			count_collectibles_and_exits(t_data *game);
int			check_rectangular_map(t_data *game);
void		check_map_shape(t_data *game);
void		check_map_walls(t_data *game);
void		check_map_characters(t_data *game);
int			verify_map_characters(t_data *game);

// flood fill

void		flood_fill(int x, int y, t_data *game, int **visited);
void		validate_map(t_data *game);
void		check_all_reached(t_data *game, int visited);
int			**allocate_memory_visited(t_data *game);
void		free_visited(int **visited, t_data *game);
void		check_reachability(t_data *game);

#endif
