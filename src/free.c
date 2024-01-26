/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:13:29 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/26 13:37:28 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
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
	free(map);
}
