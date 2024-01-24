#include "../include/so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

mlx_image_t *load_png(mlx_t* mlx, char *png)
{
	mlx_texture_t *texture;
	mlx_image_t *player_img;

	texture = mlx_load_png(png);
	if (!texture)
        error();
	player_img = mlx_texture_to_image(mlx, texture);
	if (!player_img)
        error();
	return(player_img);
}

void init_player(mlx_t	*mlx, mlx_image_t *player_img, int32_t initialX, int32_t initialY) {
    //player_img->instances->x = image;
	player_img = load_png(mlx, "textures/480px-Pacman_HD.png");
	player_img->instances->x = initialX;
    player_img->instances->y = initialY;
	mlx_image_to_window(mlx, player_img, initialX, initialY);
}

int32_t	game_init(void)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);

	mlx_t    *mlx;
	mlx_image_t *player_img;
	
	mlx = mlx_init(WIDTH, HEIGHT, "cool game", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	init_player(mlx, player_img, 100, 100);
    mlx_loop(mlx);
	mlx_close_window(mlx);
    mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}