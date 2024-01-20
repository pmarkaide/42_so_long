/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:13:29 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/20 18:06:29 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_data(t_data *data)
{
	size_t	i;

	i = 0;
	free(data->map_str);
	while (i < data->rows)
	{
		if (data->map[i] != NULL)
			free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map_str = NULL;
	data->map = NULL;
	free(data);
}
