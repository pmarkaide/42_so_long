/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:20:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/26 13:40:13 by pmarkaid         ###   ########.fr       */
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

#define WIDTH 1800
#define HEIGHT 1000

typedef struct s_map
{
	char	*map_str;
	char	**map;
	size_t	rows;
	size_t	cols;
	size_t	start_x;
	size_t	start_y;
	size_t	**visited;
}			t_map;

t_map		*map_is_valid(char *map_file, t_map *data);
size_t		count_rows_in_array(char **map);
void		free_map(t_map *data);
int			handle_error(const char *error_message);
size_t		get_file_length_in_bytes(char *map_file);
int			file_is_valid(char *map_file);
int			check_path(t_map *data);
size_t		**allocate_2d_array(size_t rows, size_t cols);
void		print_2d_array(size_t **array, size_t c);
int32_t		game_init(void);
