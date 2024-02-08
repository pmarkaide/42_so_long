/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:39:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/08 15:55:17 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

void load_textures_into_data(mlx_t *mlx, t_data *data)
{
	mlx_texture_t *texture;
	mlx_image_t *img;

	texture = mlx_load_png("textures/background.png");
	img = mlx_texture_to_image(mlx, texture);
	data->background = img;
	texture = mlx_load_png("textures/coin.png");
	img = mlx_texture_to_image(mlx, texture);
	data->coin = img;
	texture = mlx_load_png("textures/exit.png");
	img = mlx_texture_to_image(mlx, texture);
	data->exit = img;
	texture = mlx_load_png("textures/player.png");
	img = mlx_texture_to_image(mlx, texture);
	data->player = img;
	texture = mlx_load_png("textures/wall.png");
	img = mlx_texture_to_image(mlx, texture);
	data->wall = img;
}

t_data *prepare_data_struct(mlx_t *mlx, t_map *map)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	if(!data)
		free_game_and_bad_exit(data, "Malloc failed\n");
	data->map = map;
	data->pos_x =  data->map->start_x;
	data->pos_y =  data->map->start_y;
	data->moves = 0;
	load_textures_into_data(mlx, data);
	return(data);
}

void new_player_image(mlx_t *mlx, t_data *data)
{
	mlx_texture_t *texture;
	mlx_image_t *img;

	mlx_delete_image(data->mlx, data->player);
	texture = mlx_load_png("textures/player.png");
	img = mlx_texture_to_image(mlx, texture);
	data->player = img;
}

void put_map(mlx_t *mlx, t_data *data)
{
	size_t x;
	size_t y;

	x = 0;
    while (x < data->map->rows)
    {
        y = 0;
        while (y < data->map->cols)
        {
			mlx_image_to_window(mlx, data->background, y * BLOCK_SIZE, x * BLOCK_SIZE);
            if (data->map->map[x][y] == '1')
                mlx_image_to_window(mlx, data->wall, y * BLOCK_SIZE, x * BLOCK_SIZE);        
            else if (data->map->map[x][y] == 'C')
                mlx_image_to_window(mlx, data->coin, y * BLOCK_SIZE, x * BLOCK_SIZE);
            else if (data->map->map[x][y] == 'E')
                mlx_image_to_window(mlx, data->exit, y * BLOCK_SIZE, x * BLOCK_SIZE);
            y += 1;
        }
        x += 1;
    }
	mlx_image_to_window(mlx, data->player, data->map->start_y * BLOCK_SIZE, data->map->start_x * BLOCK_SIZE);
}

int32_t	game_init(t_map map)
{
	mlx_t    *mlx;
	t_data	*data;
	size_t width;
	size_t height;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	width = map.cols * BLOCK_SIZE;
	height = map.rows * BLOCK_SIZE;
	mlx = mlx_init(width, height, "Pac Man", true);
	data = prepare_data_struct(mlx, &map);
	data->height = height;
	data->width = width;
	data->mlx = mlx;
	put_map(mlx, data);
	mlx_loop_hook(mlx, quit_hook, data);
	mlx_loop_hook(mlx, exit_hook, data);
	mlx_key_hook(mlx,  (mlx_keyfunc)player_hook, data);
    mlx_loop(mlx);
	return (0);
}
