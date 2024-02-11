/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:25:34 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/02/11 12:23:23 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_1(const char *error_msg)
{
	ft_printf("%sError\n%s%s\n", RED, DEFAULT, error_msg);
	return (1);
}

char	*error_null(const char *error_msg)
{
	ft_printf("%sError\n%s%s\n", RED, DEFAULT, error_msg);
	return (NULL);
}

void	exit_1(const char *error_msg)
{
	ft_printf("%sError\n%s%s\n", RED, DEFAULT, error_msg);
	exit(1);
}
