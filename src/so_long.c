/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:14:46 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/26 13:39:49 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (argc != 2)
	{
		perror("Error\n");
		return (1);
	}
	map = map_is_valid(argv[1], map);
	if (map->map_str != NULL)
	{
		printf("Valid map!\n");
	}
	free_map(map);
	return (0);
}
