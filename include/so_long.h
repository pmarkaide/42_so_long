/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:20:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/05 19:39:24 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <memory.h>

#define BLOCK_SIZE 32

typedef struct s_map
{
	char	*map_str;
	char	**map;
	size_t	rows;
	size_t	cols;
	size_t	coins;
	size_t	start_x;
	size_t	start_y;
	size_t	exit_x;
	size_t	exit_y;
	size_t	**visited;
}			t_map;

typedef struct s_data
{	
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t* player;
	mlx_image_t* wall;
	mlx_image_t* coin;
	mlx_image_t* exit;
	mlx_image_t* background;
	size_t	height;
	size_t	width;
	size_t	pos_x;
	size_t	pos_y;
}			t_data;

t_map		*map_is_valid(char *map_file, t_map *data);
size_t		count_rows_in_array(char **map);
void		free_map(t_map *data);
void		free_game_struct(t_data *data);
int			error_1(const char *error_message);
void		error(void);
size_t		get_file_length_in_bytes(char *map_file);
int			file_is_valid(char *map_file);
int			check_path(t_map *data);
size_t		**allocate_2d_array(size_t rows, size_t cols);
void		print_2d_array(size_t **array, size_t c);
int32_t		game_init(t_map *map);
void		quit_hook(void* param);
void		player_hook(mlx_key_data_t keydata, t_data *data);
void		put_map(mlx_t *mlx, t_data *data);
void		new_player_image(mlx_t *mlx, t_data *data);
void		exit_hook(void* param);
