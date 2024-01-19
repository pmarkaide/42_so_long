/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:12:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/19 16:13:13 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	close(fd);
	return (0);
}

size_t	get_file_length_in_bytes(char *map_file)
{
	int		fd;
	char	buffer[1];
	size_t	bytes_read;

	bytes_read = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nCannot open the file");
		return (1);
	}
	while (read(fd, buffer, 1))
		bytes_read++;
	close(fd);
	if (bytes_read == 0)
	{
		perror("Error\nFile is empty");
		return (1);
	}
	else
		return (bytes_read);
}
