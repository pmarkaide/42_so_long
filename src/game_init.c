#include "../include/so_long.h"

static mlx_image_t	*g_img;
static int32_t		g_pos_x = 0;
static int32_t		g_pos_y = 0;


static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	hook(void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_pos_y -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_pos_y += 10;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_pos_x -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_pos_x += 10;

	mlx_image_to_window(mlx, g_img, g_pos_x, g_pos_y);
} 

int32_t	game_init(void)
{
	mlx_t*    mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "cool game", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	mlx_texture_t* texture = mlx_load_png("textures/480px-Pacman_HD.png");
	if (!texture)
        error();

	// Convert texture to a displayable image
	g_img = mlx_texture_to_image(mlx, texture);
	if (!g_img)
        error();

	// Set the initial position of the image
	g_pos_x = 200;
	g_pos_y = 200;

	// Display the image
	mlx_image_to_window(mlx, g_img, g_pos_x, g_pos_y);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}