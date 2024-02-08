/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:13:29 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/08 15:54:22 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void free_map(t_map *map)
{
	if (map == NULL)
		return;
	if (map->map_str != NULL)
	{
		free(map->map_str);
		map->map_str = NULL;
	}
	if (map->map != NULL)
	{
		for (size_t i = 0; i < map->rows; i++)
			free(map->map[i]);
		free(map->map);
		map->map = NULL;
	}
	if (map->visited != NULL)
	{
		for (size_t i = 0; i < map->rows; i++)
			free(map->visited[i]);
		free(map->visited);
		map->visited = NULL;
	}
}

void	 free_map_and_exit(t_map *map, char *error_msg)
{
	free_map(map);
	ft_printf("%sError\n%s%s\n", RED, DEFAULT, error_msg);
	exit(0);
}

void	free_game(t_data *data)
{
	if (data == NULL)
		exit (0);
	free_map(data->map);
	mlx_delete_image(data->mlx, data->player);
	mlx_delete_image(data->mlx, data->wall);
	mlx_delete_image(data->mlx, data->coin);
	mlx_delete_image(data->mlx, data->exit);
	mlx_delete_image(data->mlx, data->background);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
}

void	 free_game_and_bad_exit(t_data *data, char *error_msg)
{
	free_game(data);
	ft_printf("%sError\n%s%s\n", RED, DEFAULT, error_msg);
	exit (0);
}

void	 free_game_and_good_exit(t_data *data)
{
	char *error_msg = "You win the game!";
	free_game(data);
	ft_printf("%sCONGRATULATIONS!\n%s%s\n", GREEN, DEFAULT, error_msg);
	exit (0);
}
