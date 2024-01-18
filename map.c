/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:33:35 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/18 15:34:31 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
