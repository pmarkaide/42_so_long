/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:17:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/05 15:27:53 by pmarkaid         ###   ########.fr       */
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

void	player_hook(mlx_key_data_t keydata, t_data *data)
{
 	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        data->player->instances[0].x += 32;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        data->player->instances[0].x -= 32;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
        data->player->instances[0].y -= 32;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
    	data->player->instances[0].y += 32;
}
