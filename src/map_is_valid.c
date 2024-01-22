/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/22 12:32:07 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	data->visited = allocate_2d_array(data->rows, data->cols);
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
			j = 0;
			while (data->map[i][j])
			{
				if (ft_strchr("1", data->map[i][j++]) == NULL)
					return (handle_error("Error\nIncorrect walls\n"));
			}
		}
		if (data->map[i][0] != '1' || data->map[i][data->cols - 1] != '1')
			return (handle_error("Error\nIncorrect walls\n"));
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
	valid += check_path(data);
	return (data);
}
