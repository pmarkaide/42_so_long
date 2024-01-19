/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/19 15:39:35 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TO_DO
// DONE file extension is valid
// map is rectangular
// walls are correct
// only valid chars
// only one char
// valid path
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

int	load_map(char *map_file, t_data *data)
{
	int		fd;
	size_t	file_len;

	file_len = get_file_length_in_bytes(map_file);
	data->map_str = malloc(sizeof(char) * (file_len + 1));
	if (!data->map_str)
	{
		free_data(data);
		return (1);
	}
	fd = open(map_file, O_RDONLY);
	read(fd, data->map_str, file_len);
	close(fd);
	data->map_str[file_len] = '\0';
	data->map = ft_split(data->map_str, '\n');
	data->rows = count_rows_in_array(data->map);
	data->cols = ft_strlen(data->map[0]);
	return (0);
}

int	check_layout(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		if (ft_strlen(data->map[i]) != data->cols)
			return (handle_error("Error\nMap not rectangular\n"));
		if (i == 0 || i == data->rows - 1)
		{
			if (data->map[i][j] && ft_strchr("1", data->map[i][j]) == NULL)
				return (handle_error("Error\nIncorrect walls\n"));
			j = 0;
		}
		else
		{
			if (data->map[i][0] != '1' || data->map[i][data->cols - 1] != '1')
				return (handle_error("Error\nIncorrect walls\n"));
		}
		i++;
	}
	return (0);
}

int	check_chars(t_data *data)
{
	size_t	i;
	size_t	p;
	size_t	e;

	i = 0;
	p = 0;
	e = 0;
	while (data->map_str[i])
	{
		if (ft_strchr("PEC10\n", data->map_str[i]) == NULL)
			return (handle_error("Error\nNot allowed characters\n"));
		if (ft_strchr("P", data->map_str[i]))
			p++;
		if (ft_strchr("E", data->map_str[i]))
			e++;
		i++;
	}
	if (p > 1 || e > 1)
		return (handle_error("Error\nRepeated characters\n"));
	return (0);
}

t_data	*map_is_valid(char *map_file, t_data *data)
{
	int	valid;

	valid = 0;
	valid += file_is_valid(map_file);
	valid += load_map(map_file, data);
	valid += check_layout(data);
	valid += check_chars(data);
	if (valid != 0)
		ft_printf("Map NOT valid!\n");
	return (data);
}
