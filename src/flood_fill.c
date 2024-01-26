/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:15:01 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/26 13:53:13 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_position(size_t x, size_t y, t_map *map)
{
	if (x < 0 || x >= map->rows)
		return (0);
	if (y < 0 || y >= map->cols)
		return (0);
	if (map->map[x][y] == '1')
		return (0);
	if (map->visited[x][y])
		return (0);
	return (1);
}

void	flood_fill(int x, int y, t_map *map)
{
	if (!is_valid_position(x, y, map))
		return ;
	map->visited[x][y] = 1;
	flood_fill(x - 1, y, map);
	flood_fill(x + 1, y, map);
	flood_fill(x, y - 1, map);
	flood_fill(x, y + 1, map);
}

// starting position calculation
// check C and E against visited

void	get_starting_point(t_map *map)
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
				return ;
			}
			j++;
		}
		i++;
	}
}

int	check_path(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	get_starting_point(map);
	flood_fill(map->start_x, map->start_y, map);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'C' || map->map[i][j] == 'E')
			{
				if (!map->visited[i][j])
					return (error_1("Error\nNo valid path exists!\n"));
			}
			j++;
		}
		i++;
	}
	return (0);
}
