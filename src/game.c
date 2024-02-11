/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:39:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/11 12:18:19 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	prepare_data_struct(t_data *data, t_map *map)
{
	ft_bzero(data, sizeof(*data));
	data->map = map;
	data->pos_x = data->map->start_x;
	data->pos_y = data->map->start_y;
	data->width = data->map->cols * BLOCK_SIZE;
	data->height = data->map->rows * BLOCK_SIZE;
}

void	load_images_into_struct(t_data *data, mlx_t *mlx)
{
	data->mlx = mlx;
	data->background = load_png_into_image(data, "textures/background.png");
	data->coin = load_png_into_image(data, "textures/coin.png");
	data->exit = load_png_into_image(data, "textures/exit.png");
	data->player = load_png_into_image(data, "textures/player.png");
	data->wall = load_png_into_image(data, "textures/wall.png");
}

int32_t	game_init(t_map map)
{
	mlx_t	*mlx;
	t_data	data;

	prepare_data_struct(&data, &map);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(data.width, data.height, "Pac Man", true);
	if (!mlx)
		free_game_and_bad_exit(&data, "mlx initiation failed");
	load_images_into_struct(&data, mlx);
	render_map(&data);
	mlx_loop_hook(mlx, quit_hook, &data);
	mlx_loop_hook(mlx, exit_hook, &data);
	mlx_key_hook(mlx, (mlx_keyfunc)player_hook, &data);
	mlx_loop(mlx);
	return (0);
}
