/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:20:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/20 12:25:32 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_data
{
	char	*map_str;
	char	**map;
	char	**visited;
	size_t	rows;
	size_t	cols;
}			t_data;

t_data		*map_is_valid(char *map_file, t_data *data);
size_t		count_rows_in_array(char **map);
void		free_data(t_data *data);
int			handle_error(const char *error_message);
size_t	get_file_length_in_bytes(char *map_file);
int	file_is_valid(char *map_file);
