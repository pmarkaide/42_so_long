/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:39:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/09 18:16:01 by pmarkaid         ###   ########.fr       */
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

void prepare_data_struct(t_data *data, t_map *map)
{
	ft_bzero(data, sizeof(*data));
	data->map = map;
	data->pos_x =  data->map->start_x;
	data->pos_y =  data->map->start_y;
	data->width = data->map->cols * BLOCK_SIZE;
	data->height = data->map->rows * BLOCK_SIZE;
}

void load_images_into_struct(t_data *data, mlx_t	*mlx)
{
	data->mlx = mlx;
	data->background = load_png_into_image(data, "textures/background.png");
	data->coin =  load_png_into_image(data, "textures/coin.png");
	data->exit =  load_png_into_image(data, "textures/exit.png");
	data->player = load_png_into_image(data, "textures/player.png");
	data->wall= load_png_into_image(data, "textures/wall.png");
}

void new_player_image(t_data *data)
{
	mlx_delete_image(data->mlx, data->player);
	data->player = load_png_into_image(data, "textures/player.png");
}

void render_block(t_data *data, mlx_image_t *img, size_t y, size_t x)
{
	int exit_code;
	exit_code = mlx_image_to_window(data->mlx, img, y * BLOCK_SIZE, x * BLOCK_SIZE);
	if(exit_code == -1)
		free_game_and_bad_exit(data, "Render problems");
}

void render_map(t_data *data)
{
	size_t x;
	size_t y;

	x = 0;
	while (x < data->map->rows)
	{
		y = 0;
		while (y < data->map->cols)
		{
			render_block(data, data->background, y, x);
			if (data->map->map[x][y] == '1')
				render_block(data, data->wall, y, x);
			else if (data->map->map[x][y] == 'C')
				render_block(data, data->coin, y, x);
			else if (data->map->map[x][y] == 'E')
				render_block(data, data->exit, y, x);
			y += 1;
		}
		x += 1;
	}
	render_block(data, data->player, data->map->start_y, data->map->start_x);
}

int32_t	game_init(t_map map)
{
	mlx_t	*mlx;
	t_data	data;

	prepare_data_struct(&data, &map);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(data.width, data.height, "Pac Man", true);
	if(!mlx)
		free_game_and_bad_exit(&data, "mlx initiation failed");
	load_images_into_struct(&data, mlx);
	render_map(&data);
	mlx_loop_hook(mlx, quit_hook, &data);
	mlx_loop_hook(mlx, exit_hook, &data);
	mlx_key_hook(mlx,  (mlx_keyfunc)player_hook, &data);
	mlx_loop(mlx);
	return (0);
}
