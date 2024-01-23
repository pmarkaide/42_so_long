#include "../include/so_long.h"

static mlx_image_t	*g_img;

void	hook(void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_P))
		mlx_delete_image(mlx, g_img);
} 

int32_t	game_init(void)
{
	mlx_t*    mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "cool game", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}