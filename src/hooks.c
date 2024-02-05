/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:17:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/05 16:26:22 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_hook(void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int is_valid_move(t_data *data, int x, int y)
{
    if(data->map->map[x][y] == '1')
		return(0);
	if(data->map->map[x][data->pos_y] <= 0)
		return(0);
	if(data->map->map[data->pos_x][y] <= 0)
		return(0);
	return(1);
}

void move_player(t_data *data, int dx, int dy) {
    int new_x = data->pos_x + dx;
    int new_y = data->pos_y + dy;

	if(is_valid_move(data, new_x, new_y))
	{
		data->player->instances[0].x = new_y * BLOCK_SIZE;
		data->player->instances[0].y = new_x * BLOCK_SIZE;
		data->pos_x = new_x;
		data->pos_y = new_y;
	}	
}

void player_hook(mlx_key_data_t keydata, t_data *data) {
    if (keydata.action == MLX_PRESS) {
        if (keydata.key == MLX_KEY_RIGHT)
            move_player(data, 0, 1);
       	else if (keydata.key == MLX_KEY_LEFT)
            move_player(data, 0, -1);
        else if (keydata.key == MLX_KEY_UP)
        	move_player(data, -1, 0);
        else if (keydata.key == MLX_KEY_DOWN)
            move_player(data, 1, 0);
    }
}
