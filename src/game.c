#include "../include/so_long.h"

void load_textures(mlx_t *mlx, t_data *data)
{
	xpm_t *player_texture;
	mlx_image_t *player;

	player_texture = mlx_load_xpm42("textures/player.xpm42");
	if (!player_texture)
	{
    	printf("xpm load failed!");
		error();
	}
	player = mlx_texture_to_image(mlx, &player_texture->texture);
	if (!player)
	{
    	printf("texture to image failed!");
		error();
	}
	data->player = player;
}


t_data *prepare_game_struct(mlx_t *mlx, t_map *map)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	if(!data)
		error();
	data->map = map;
	load_textures(mlx, data);
	return(data);
}


int32_t	game_init(t_map *map)
{
	mlx_t    *mlx;
	t_data	*data;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);	
	mlx = mlx_init(WIDTH, HEIGHT, "cool game", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	data = prepare_game_struct(mlx, map);
	mlx_image_to_window(mlx, data->player, 100, 100);
    mlx_loop(mlx);
	mlx_close_window(mlx);
    mlx_terminate(mlx);
	free_game_struct(data);
	return (EXIT_SUCCESS);
}
