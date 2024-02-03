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
		error();
	data->map = map;
	load_textures_into_data(mlx, data);
	return(data);
}

void put_background(mlx_t *mlx, t_data *data)
{
	size_t w;
	size_t h;

	w = 0;
	h = 0;
	while(h < HEIGHT)
		{
		while(w < WIDTH)
		{
			mlx_image_to_window(mlx, data->background, w, h);
			w += 32;
		}
	w = 0;
	h += 32;
	}
}

int32_t	game_init(t_map *map)
{
	mlx_t    *mlx;
	t_data	*data;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);	
	mlx = mlx_init(WIDTH, HEIGHT, "cool game", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	data = prepare_data_struct(mlx, map);
	put_background(mlx, data);
    mlx_loop(mlx);
	mlx_close_window(mlx);
    mlx_terminate(mlx);
	free_game_struct(data);
	return (EXIT_SUCCESS);
}
