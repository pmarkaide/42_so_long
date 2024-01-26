#include "../include/so_long.h"

t_data *prepare_game_struct(t_map *map)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	if(!data)
		error();
	data->map = map;
	return(data);
}


int32_t	game_init(t_map *map)
{
	mlx_t    *mlx;
	t_data	*data;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);	
	data = prepare_game_struct(map);
	mlx = mlx_init(WIDTH, HEIGHT, "cool game", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	printf("%s\n", data->map->map_str);
    mlx_loop(mlx);
	mlx_close_window(mlx);
    mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
