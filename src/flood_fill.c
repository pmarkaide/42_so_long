/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:15:01 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/08 15:41:01 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_position(t_map *map, size_t x, size_t y)
{
	if (x >= map->rows)
		return (0);
	if (y >= map->cols)
		return (0);
	if (map->map[x][y] == '1')
		return (0);
	if (map->visited[x][y])
		return (0);
	return (1);
}

void	flood_fill(t_map *map, size_t x, size_t y)
{
	if (!is_valid_position(map, x, y))
		return ;
	map->visited[x][y] = 1;
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

void	get_start_and_exit_points(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
			{
				map->start_x = i;
				map->start_y = j;
			}
			if (map->map[i][j] == 'E')
			{
				map->exit_x = i;
				map->exit_y = j;
			}
			j++;
		}
		i++;
	}
}

void	check_path(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	get_start_and_exit_points(map);
	flood_fill(map, map->start_x, map->start_y);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'C' || map->map[i][j] == 'E')
			{
				if (!map->visited[i][j])
					free_map_and_exit(map, "No valid path exists!");
			}
			j++;
		}
		i++;
	}
}
