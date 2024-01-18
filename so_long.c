/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:14:46 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/18 17:39:54 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 2)
	{
		perror("Error\n");
		return (1);
	}
	data = map_is_valid(argv[1], data);
	if (data != NULL)
    {
		//run game
        free_data(data);
    }
	return (0);
}
