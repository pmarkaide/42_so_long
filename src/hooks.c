/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:17:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/05 10:58:35 by pmarkaid         ###   ########.fr       */
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

void	player_hook(void *param)
{
	t_data *data;
	
	data = param;
 	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
        data->player->instances[0].x -= 10;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
        data->player->instances[0].x += 10;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
        data->player->instances[0].y -= 10;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
        data->player->instances[0].y += 10;
}