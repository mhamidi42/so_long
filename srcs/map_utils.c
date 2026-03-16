/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:10:30 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 15:11:30 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i] != NULL)
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i] != NULL)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	find_pos(char **map, char c, int *res_y, int *res_x)
{
	int		y;
	int		x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
			{
				*res_y = y;
				*res_x = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	right2(t_data *game)
{
	if (game->map[game->x][game->y + 1] == 'C')
	{
		game->map[game->x][game->y + 1] = 'P';
		game->map[game->x][game->y] = '0';
		game->nb_move++;
	}
}

void	left2(t_data *game)
{
	if (game->map[game->x][game->y - 1] == 'C')
	{
		game->map[game->x][game->y - 1] = 'P';
		game->map[game->x][game->y] = '0';
		game->nb_move++;
	}	
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}
