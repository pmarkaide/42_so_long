/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:12:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/09 13:46:09 by pmarkaid         ###   ########.fr       */
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
	extension = strrchr(map_file, '.');
	if (extension == NULL || strcmp(extension, ".ber") != 0)
		exit_1("Invalid file extension. Expected: '.ber'");
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit_1("Cannot open the file");
	else
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read == 0)
			exit_1("File is empty");
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

size_t	get_rows(char **array)
{
	size_t	rows;

	rows = 0;
	while (array[rows] != NULL)
		rows++;
	return (rows);
}

size_t	get_cols(char **array)
{
	size_t	cols;

	cols = 0;
	while (array[0][cols] != '\0')
		cols++;
	return (cols);
}

void	print_2d_array(char **array)
{
	size_t	rows;
	size_t	i;

	rows = get_rows(array);
	i = 0;
	while (i < rows)
	{
		ft_printf("%s", array[i]);
		ft_printf("\n");
		i++;
	}
}
