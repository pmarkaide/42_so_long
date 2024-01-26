/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/26 13:37:02 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	load_map(char *map_file, t_map *map)
{
	int		fd;
	size_t	file_len;

	file_len = get_file_length_in_bytes(map_file);
	map->map_str = malloc(sizeof(char) * (file_len + 1));
	if (!map->map_str)
	{
		free_map(map);
		return (1);
	}
	fd = open(map_file, O_RDONLY);
	read(fd, map->map_str, file_len);
	close(fd);
	map->map_str[file_len] = '\0';
	map->map = ft_split(map->map_str, '\n');
	map->rows = count_rows_in_array(map->map);
	map->cols = ft_strlen(map->map[0]);
	map->visited = allocate_2d_array(map->rows, map->cols);
	return (0);
}

int	check_layout(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		if (ft_strlen(map->map[i]) != map->cols)
			return (handle_error("Error\nMap not rectangular\n"));
		if (i == 0 || i == map->rows - 1)
		{
			j = 0;
			while (map->map[i][j])
			{
				if (ft_strchr("1", map->map[i][j++]) == NULL)
					return (handle_error("Error\nIncorrect walls\n"));
			}
		}
		if (map->map[i][0] != '1' || map->map[i][map->cols - 1] != '1')
			return (handle_error("Error\nIncorrect walls\n"));
		i++;
	}
	return (0);
}

int	check_chars(t_map *map)
{
	size_t	i;
	size_t	p;
	size_t	e;

	i = 0;
	p = 0;
	e = 0;
	while (map->map_str[i])
	{
		if (ft_strchr("PEC10\n", map->map_str[i]) == NULL)
			return (handle_error("Error\nNot allowed characters\n"));
		if (ft_strchr("P", map->map_str[i]))
			p++;
		if (ft_strchr("E", map->map_str[i]))
			e++;
		i++;
	}
	if (p > 1 || e > 1)
		return (handle_error("Error\nRepeated characters\n"));
	return (0);
}

t_map	*map_is_valid(char *map_file, t_map *map)
{
	int	valid;

	valid = 0;
	valid += file_is_valid(map_file);
	valid += load_map(map_file, map);
	valid += check_layout(map);
	valid += check_chars(map);
	valid += check_path(map);
	if(valid > 0)
		map->map_str = NULL;
	return (map);
}