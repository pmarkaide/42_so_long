/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:13:29 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/18 17:28:26 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_data(t_data *data) {
    size_t i;
	
	i = 0;
	free(data->map_str);
	while (i < data->rows)
	{
		ft_printf("Row %d freed...\n", i);
		ft_printf("%s\n", data->map[i]);
		free(data->map[i]);
		i++;
	}
    free(data->map);
	data->map_str = NULL;
    data->map = NULL;
    free(data);
}