/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:12:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/22 12:32:13 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

size_t	**allocate_2d_array(size_t rows, size_t cols)
{
	size_t	**array;
	size_t	i;
	size_t	j;

	array = malloc(rows * sizeof(size_t *));
	i = 0;
	while (i < rows)
	{
		array[i] = malloc(cols * sizeof(size_t));
		j = 0;
		while (j < cols)
			array[i][j++] = 0;
		i++;
	}
	return (array);
}

size_t	get_rows(size_t **array)
{
	size_t	rows;

	rows = 0;
	while (array[rows] != NULL)
		rows++;
	return (rows);
}

size_t	get_cols(size_t **array, size_t c)
{
	size_t	cols;

	cols = 0;
	while (array[0][cols] == c)
		cols++;
	return (cols);
}

void	print_2d_array(size_t **array, size_t c)
{
	size_t	rows;
	size_t	cols;
	size_t	i;
	size_t	j;

	rows = get_rows(array);
	cols = get_cols(array, c);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols - 1)
			printf("%zu ", array[i][j++]);
		printf("\n");
		i++;
	}
}