/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:17:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/03 16:51:08 by pmarkaid         ###   ########.fr       */
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


// void my_keyhook(mlx_key_data_t keydata, t_data *data)
// {
// 	// If we PRESS the 'J' key, print "Hello".
// 	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
// 		puts("Hello ");

// 	// If we RELEASE the 'K' key, print "World".
// 	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
// 		puts("World");

// 	// If we HOLD the 'L' key, print "!".
// 	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
// 		puts("!");
// }

// void key_hook_wrapper(int keycode, void *param)
// {
//     mlx_key_data_t keydata;
// 	t_data *data = (t_data *)param;
//     keydata.key = keycode;
//     player_hook(keydata, data);
// }

// void player_hook(mlx_key_data_t keydata, t_data *data)
// {	
//     if (keydata.key == MLX_KEY_LEFT) {
//         data->player->instances[0].x -= 10;
//     } else if (keydata.key == MLX_KEY_RIGHT) {
//         data->player->instances[0].x += 10;
//     } else if (keydata.key == MLX_KEY_UP) {
//         data->player->instances[0].y -= 10;
//     } else if (keydata.key == MLX_KEY_DOWN) {
//         data->player->instances[0].y += 10;
//     }
// }

void	player_hook(void *param)
{
	t_data *data;
	
	data = param;
	printf("Player hook called!\n");
 	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
        data->player->instances[0].x -= 10;
		printf("Left key pressed!\n");
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
        data->player->instances[0].x += 10;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
        data->player->instances[0].y -= 10;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
        data->player->instances[0].y += 10;
}