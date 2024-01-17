/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/17 14:11:40 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TO_DO
// DONE file extension is valid
//map is rectangular
//walls are correct
//only valid chars
//only one char
//valid path
//

int	file_is_valid(char *map_file)
{
	char	*extension;
	int		fd;

	extension = strrchr(map_file, '.');
	if (extension == NULL || strcmp(extension, ".ber") != 0)
	{
		perror("Error: Invalid file extension. Expected '.ber'.\n");
		return (1);
	}
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	return (0);
}

int	map_is_valid(char *map_file, t_data *data)
{
	int	valid;

	valid = 0;
	valid += file_is_valid(map_file);
	valid += load_map(map_file);
	data->rows = 0;
	return (0);
}
