/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:15:01 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/20 11:30:57 by pmarkaid         ###   ########.fr       */
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
		return;
	data->visited[x][y] = 1;
	flood_fill(x - 1, y, data);
	flood_fill(x + 1, y, data);
	flood_fill(x, y - 1, data);
	flood_fill(x, y + 1, data);
}

// starting position calculation
// check C and E against visited

int map_has_valid_path(t_data *data)
{
int startX, startY; // Identify the starting point (player position)

    // Find the starting position 'P'
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            if (data->map[i][j] == 'P') {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    floodFill(startX, startY);

    // Check if all collectibles and exit are visited
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            if ((data->map[i][j] == 'C' || data->map[i][j] == 'E') && !visited[i][j]) {
                printf("Invalid path!\n");
                return 0;
            }
        }
    }

    printf("Valid path exists!\n");

    return 0;
}