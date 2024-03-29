/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:12:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/12 10:29:49 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	file_is_valid(char *map_file)
{
	char	*extension;
	int		fd;
	char	buffer[1];
	size_t	bytes_read;

	bytes_read = 0;
	extension = ft_strrchr(map_file, '.');
	if (extension == NULL || ft_strncmp(extension, ".ber", 4) != 0)
		exit_1("Invalid file extension. Expected: '.ber'");
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit_1("Cannot open the file");
	else
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read <= 0)
			exit_1("File is empty or couldn't be read");
	}
	close(fd);
}

size_t	get_file_length_in_bytes(char *map_file)
{
	int		fd;
	char	buffer[1];
	size_t	bytes_read;

	bytes_read = 0;
	fd = open(map_file, O_RDONLY);
	while (read(fd, buffer, 1))
		bytes_read++;
	close(fd);
	return (bytes_read);
}

char	*read_whole_file(char *file)
{
	int		fd;
	char	*buffer;
	size_t	file_len;
	size_t	bytes_read;

	file_is_valid(file);
	file_len = get_file_length_in_bytes(file);
	buffer = malloc(sizeof(char) * (file_len + 1));
	if (!buffer)
		exit_1("Malloc problems");
	fd = open(file, O_RDONLY);
	bytes_read = read(fd, buffer, file_len);
	if (bytes_read <= 0)
		exit_1("File is empty or couldn't be read");
	close(fd);
	return (buffer);
}

size_t	**allocate_2d_array(size_t rows, size_t cols)
{
	size_t	**array;
	size_t	i;
	size_t	j;

	array = malloc((rows + 1) * sizeof(size_t *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		array[i] = malloc(cols * sizeof(size_t));
		if (array == NULL)
			return (NULL);
		j = 0;
		while (j < cols)
			array[i][j++] = 0;
		i++;
	}
	array[rows] = NULL;
	return (array);
}

size_t	count_rows_in_array(char **map)
{
	size_t	count;

	count = 0;
	while (map[count] != NULL)
	{
		count++;
	}
	return (count);
}
