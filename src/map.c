/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:33:35 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/20 18:06:29 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
