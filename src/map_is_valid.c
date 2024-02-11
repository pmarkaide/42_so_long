/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/11 14:30:47 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_map(char *map_file, t_map *map)
{
	int		fd;
	size_t	file_len;

	file_len = get_file_length_in_bytes(map_file);
	map->map_str = malloc(sizeof(char) * (file_len + 1));
	if (!map->map_str)
		exit_1("Malloc problems");
	fd = open(map_file, O_RDONLY);
	read(fd, map->map_str, file_len);
	close(fd);
	map->map_str[file_len] = '\0';
	if (map->map_str[file_len - 1] == '\n' || map->map_str[0] == '\n')
		free_map_and_exit(map, "Empty line in map");
	map->map = ft_split(map->map_str, '\n');
	if (!map->map[0] || map->map == NULL)
		free_map_and_exit(map, "Map layout not correct");
	map->rows = count_rows_in_array(map->map);
	map->cols = ft_strlen(map->map[0]);
	map->visited = allocate_2d_array(map->rows, map->cols);
}

void	check_layout(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		if (ft_strlen(map->map[i]) != map->cols)
			free_map_and_exit(map, "Map not rectangular");
		if (i == 0 || i == map->rows - 1)
		{
			j = 0;
			while (map->map[i][j])
			{
				if (ft_strchr("1", map->map[i][j++]) == NULL)
					free_map_and_exit(map, "Incorrect walls");
			}
		}
		if (map->map[i][0] != '1' || map->map[i][map->cols - 1] != '1')
			free_map_and_exit(map, "Incorrect walls");
		i++;
	}
}

void	check_chars(t_map *map)
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
			free_map_and_exit(map, "Not allowed characters");
		if (ft_strchr("P", map->map_str[i]))
			p++;
		if (ft_strchr("E", map->map_str[i]))
			e++;
		if (ft_strchr("C", map->map_str[i]))
			map->coins++;
		i++;
	}
	if (p != 1 || e != 1 || map->coins == 0)
		free_map_and_exit(map, "Map need 1 exit, 1 player and >0 coins");
}

void	map_is_valid(char *map_file, t_map *map)
{
	ft_bzero(map, sizeof(*map));
	file_is_valid(map_file);
	load_map(map_file, map);
	check_layout(map);
	check_chars(map);
	check_path(map);
}
