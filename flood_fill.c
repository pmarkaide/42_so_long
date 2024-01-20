/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:15:01 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/20 16:10:46 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_position(size_t x, size_t y, t_data *data)
{
	if (x < 0 || x >= data->rows)
		return (0);
	if (y < 0 || y >= data->cols)
		return (0);
	if (data->map[x][y] == '1')
		return (0);
	if (data->visited[x][y])
		return (0);
	return (1);
}

void	flood_fill(int x, int y, t_data *data)
{
	if (!is_valid_position(x, y, data))
		return ;
	data->visited[x][y] = 1;
	flood_fill(x - 1, y, data);
	flood_fill(x + 1, y, data);
	flood_fill(x, y - 1, data);
	flood_fill(x, y + 1, data);
}

// starting position calculation
// check C and E against visited

void	get_starting_point(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == 'P')
			{
				data->start_x = i;
				data->start_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	check_path(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	get_starting_point(data);
	flood_fill(data->start_x, data->start_y, data);
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == 'C' || data->map[i][j] == 'E')
			{
				if (!data->visited[i][j])
					return (handle_error("Error\nNo valid path exists!\n"));
			}
			j++;
		}
		i++;
	}
	return (0);
}
