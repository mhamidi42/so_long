/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:13:31 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 15:13:33 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line_one(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_line_last(char **map)
{
	int	a;
	int	z;
	int	i;

	z = 0;
	a = 0;
	i = 0;
	while (map[z] != NULL)
	{
		z++;
		a++;
	}
	a = a - 1;
	while (map[a][i] != '\0')
	{
		if (map[a][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_first_column(char **map)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][y] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_last_column(char **map)
{
	int	i;
	int	y;

	y = 0;
	i = ft_strlen(map[0]);
	i = i - 1;
	while (map[y] != NULL)
	{
		if (map[y][i] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	map_wall_checker(char **map)
{
	if (check_line_one(map) == 1)
	{
		printf("line one error\n");
		return (1);
	}
	if (check_line_last(map) == 1)
	{
		printf("last line error\n");
		return (1);
	}
	if (check_first_column(map) == 1)
	{
		printf("first colomn error\n");
		return (1);
	}
	if (check_last_column(map) == 1)
	{
		printf("last column error\n");
		return (1);
	}
	return (0);
}
