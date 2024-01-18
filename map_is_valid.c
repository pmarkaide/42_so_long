/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/18 17:44:16 by pmarkaid         ###   ########.fr       */
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
	char	*map_str;

	file_len = get_file_length_in_bytes(map_file);
	printf("File size is: %zu\n",file_len);
	map_str = malloc(sizeof(char) * file_len + 1);
	if (!map_str)
		return (1);
	printf("Malloc correct");
	fd = open(map_file, O_RDONLY);
	read(fd, map_str, file_len);
	close(fd);
	data->map_str = map_str;
	ft_printf("map:\n%s\n", data->map_str);
	data->map = ft_split(map_str, '\n');
	
	data->rows = count_rows_in_array(data->map);
	printf("rows: %zu\n", data->rows);
	data->cols = ft_strlen(data->map[0]);
	printf("cols: %zu\n", data->cols);
	return (0);
}

int check_chars(t_data *data)
{
	size_t i;

	i = 0;
	while(data->map_str[i])
	{
		if(ft_strchr("PEC10\n", data->map_str[i]) == NULL)
		{
			perror("Error\nNot allowed characters\n");
			return(1);
		}
		i++;
	}
	i = 0;
	while(i < data->rows)
	{
		if(ft_strlen(data->map[i]) != data->cols)
		{
			perror("Error\nMap not reactangular\n");
			return(1);
		}
		i++;
	}
	return(0);	
}

t_data	*map_is_valid(char *map_file, t_data *data)
{
	int	valid;

	valid = 0;
	valid += file_is_valid(map_file);
	ft_printf("File is valid!\n");
	valid += load_map(map_file, data);
	ft_printf("Loading map!\n");
	//valid += check_chars(data);
	if(valid == 0)
		ft_printf("Valid map!\n");
	else
		ft_printf("Map NOT valid!\n");
	// size_t i = 0;
	// while (i < data->rows)
	// {
	// 	ft_printf("Row %d freed...\n", i);
	// 	ft_printf("%s\n", data->map[i]);
	// 	i++;
	// }
	return (data);
}
