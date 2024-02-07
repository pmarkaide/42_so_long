/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:12:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/07 12:13:14 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	file_is_valid(char *map_file)
{
	char	*extension;
	int		fd;

	extension = strrchr(map_file, '.');
	if (extension == NULL || strcmp(extension, ".ber") != 0)
		return(error_1("Error\nInvalid file extension. Expected '.ber'.\n"));
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return(error_1("Error\nCannot open the file\n"));
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
	while (read(fd, buffer, 1))
		bytes_read++;
	close(fd);
	if (bytes_read == 0)
		return(error_1("Error\nFile is empty\n"));
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
			ft_printf("%zu ", array[i][j++]);
		ft_printf("\n");
		i++;
	}
}
