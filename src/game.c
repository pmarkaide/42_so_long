/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:39:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/08 17:33:16 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

mlx_image_t	*load_png_into_image(t_data *data, char *file)
{
	mlx_texture_t *texture;
	mlx_image_t *img;

	texture = mlx_load_png(file);
	if(!texture)
		free_game_and_bad_exit(data,"Reading png file failed");
	img = mlx_texture_to_image(data->mlx, texture);
	if(!img)
		free_game_and_bad_exit(data,"Malloc failed");
	mlx_delete_texture(texture);
	return(img);
}

void load_textures_into_data(t_data *data)
{
	data->background = load_png_into_image(data, "textures/background.png");
	data->coin =  load_png_into_image(data, "textures/coin.png");
	data->exit =  load_png_into_image(data, "textures/exit.png");
	data->player = load_png_into_image(data, "textures/player.png");
	data->wall= load_png_into_image(data, "textures/wall.png");
}

t_data *prepare_data_struct(t_map *map, mlx_t *mlx)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if(!data)
		free_game_and_bad_exit(data, "Malloc failed");
	ft_bzero(&(*data), sizeof(*data));
	data->map = map;
	data->mlx = mlx;
	data->pos_x =  data->map->start_x;
	data->pos_y =  data->map->start_y;
	load_textures_into_data(data);
	return(data);
}

void new_player_image(t_data *data)
{
	mlx_delete_image(data->mlx, data->player);
	data->player = load_png_into_image(data, "textures/player.png");
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
	if(!mlx)
		free_map_and_exit(&map, "mlx initiation failed");
	data = prepare_data_struct(&map, mlx);
	data->height = height;
	data->width = width;
	put_map(mlx, data);
	mlx_loop_hook(mlx, quit_hook, data);
	mlx_loop_hook(mlx, exit_hook, data);
	mlx_key_hook(mlx,  (mlx_keyfunc)player_hook, data);
	mlx_loop(mlx);
	return (0);
}
