/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:07:41 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 15:09:53 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == WALL || map[y][x] == ' ')
		return ;
	map[y][x] = ' ';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
}

int	map_path_check(char **map)
{
	char	**copy;
	int		y_player;
	int		x_player;

	copy = copy_map(map);
	if (!find_pos(copy, PLAYER, &y_player, &x_player))
		return (free_tab(copy), 1);
	flood_fill(copy, y_player, x_player);
	if (find_pos(copy, PLAYER, &y_player, &x_player))
		return (free_tab(copy), 1);
	if (find_pos(copy, COIN, &y_player, &x_player))
		return (free_tab(copy), 1);
	if (find_pos(copy, DOOR, &y_player, &x_player))
	{
		return (free_tab(copy), 1);
	}
	free_tab(copy);
	return (0);
}
