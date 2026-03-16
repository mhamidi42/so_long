/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:14:19 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 15:15:23 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coin_count(char **map)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == COIN)
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	position_player(char **map, int *i, int *j)
{
	*i = 0;
	while (map[*i] != NULL)
	{
		*j = 0;
		while (map[*i][*j] != '\0')
		{
			if (map[*i][*j] == 'P')
				return ;
			(*j)++;
		}
		(*i)++;
	}
}

void	up2(t_data *game)
{
	if (game->map[game->x - 1][game->y] == 'C')
	{
		game->map[game->x - 1][game->y] = 'P';
		game->map[game->x][game->y] = '0';
		game->nb_move++;
	}
}

void	down2(t_data *game)
{
	if (game->map[game->x + 1][game->y] == 'C')
	{
		game->map[game->x + 1][game->y] = 'P';
		game->map[game->x][game->y] = '0';
		game->nb_move++;
	}
}
