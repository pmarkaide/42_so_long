/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:15:01 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/19 17:30:21 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_path(int x, int y, t_data *data)
{
	if (x < 0 || x >= data->rows)
		return (1);
	if (y < 0 || y >= data->cols)
		return (1);
	if (data->map[x][y] == '1')
		return (1);
	if (data->visited[x][y])
		return (1);
	return (0);
}

void	flood_fill(int x, int y, t_data *data)
{
	if (!is_valid_path(x, y, data))
	{
		return ;
	}
	data->visited[x][y] = 1;
	flood_fill(x - 1, y, data);
	flood_fill(x + 1, y, data);
	flood_fill(x, y - 1, data);
	flood_fill(x, y + 1, data);
}

// starting position calculation
// check C and E against visited