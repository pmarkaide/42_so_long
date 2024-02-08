/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:14:46 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/08 15:45:40 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return(error_1("\nERROR! Usage:\t./so_long maps/valid_0.ber\n"));
	map_is_valid(argv[1], &map);
	game_init(map);
	return (0);
}
