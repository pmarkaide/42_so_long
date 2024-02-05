/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:13:29 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/05 19:35:46 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->map_str != NULL)
		free(map->map_str);
	while (i < map->rows)
	{
		if (map->map[i] != NULL)
			free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map_str = NULL;
	map->map = NULL;
	//free(map);
}

void free_game_struct(t_data *data)
{
	free_map(data->map);
    free(data);
}
