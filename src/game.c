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
            if (data->map->map[x][y] == '1')
                mlx_image_to_window(mlx, data->wall, y * BLOCK_SIZE, x * BLOCK_SIZE);
            else if (data->map->map[x][y] == 'P')
                mlx_image_to_window(mlx, data->player, y * BLOCK_SIZE, x * BLOCK_SIZE);
            else if (data->map->map[x][y] == 'C')
                mlx_image_to_window(mlx, data->coin, y * BLOCK_SIZE, x * BLOCK_SIZE);
            else if (data->map->map[x][y] == 'E')
                mlx_image_to_window(mlx, data->exit, y * BLOCK_SIZE, x * BLOCK_SIZE);
            else
                mlx_image_to_window(mlx, data->background, y * BLOCK_SIZE, x * BLOCK_SIZE);

            y += 1;
        }
        x += 1;
    }
}

int32_t	game_init(t_map *map)
{
	mlx_t    *mlx;
	t_data	*data;
	size_t width;
	size_t height;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	width = map->cols * BLOCK_SIZE;
	height = map->rows * BLOCK_SIZE;
	mlx = mlx_init(width, height, "cool game", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	data = prepare_data_struct(mlx, map);
	data->height = height;
	data->width = width;
	put_map(mlx, data);
	mlx_loop_hook(mlx, exit_hook, mlx);
	mlx_loop_hook(mlx, player_hook, data);
    mlx_loop(mlx);
	mlx_close_window(mlx);
    mlx_terminate(mlx);
	free_game_struct(data);
	return (EXIT_SUCCESS);
}
