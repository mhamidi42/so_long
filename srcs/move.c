/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:16:31 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 15:18:36 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*up(t_data *game)
{
	position_player(game->map, &game->x, &game->y);
	if (game->map[game->x - 1][game->y] == '1')
		return (game);
	if (game->map[game->x - 1][game->y] == '0')
	{
		game->map[game->x - 1][game->y] = 'P';
		game->map[game->x][game->y] = '0';
		game->nb_move++;
		return (game);
	}
	if (game->map[game->x - 1][game->y] == 'E')
	{
		if (coin_count(game->map) == 0)
		{
			game->nb_move++;
			close_image(game);
			exit(0);
		}
		else
			return (game);
	}
	up2(game);
	return (game);
}

t_data	*down(t_data *game)
{
	position_player(game->map, &game->x, &game->y);
	if (game->map[game->x + 1][game->y] == '1')
		return (game);
	if (game->map[game->x + 1][game->y] == '0')
	{
		game->map[game->x + 1][game->y] = 'P';
		game->map[game->x][game->y] = '0';
		game->nb_move++;
		return (game);
	}
	if (game->map[game->x + 1][game->y] == 'E')
	{
		if (coin_count(game->map) == 0)
		{
			game->nb_move++;
			close_image(game);
			exit(0);
		}
		else
			return (game);
	}
	down2(game);
	return (game);
}

t_data	*right(t_data *game)
{
	position_player(game->map, &game->x, &game->y);
	if (game->map[game->x][game->y + 1] == '1')
		return (game);
	if (game->map[game->x][game->y + 1] == '0')
	{
		game->map[game->x][game->y + 1] = 'P';
		game->map[game->x][game->y] = '0';
		game->nb_move++;
		return (game);
	}
	if (game->map[game->x][game->y + 1] == 'E')
	{
		if (coin_count(game->map) == 0)
		{
			game->nb_move++;
			close_image(game);
			exit(0);
		}
		else
			return (game);
	}
	right2(game);
	return (game);
}

t_data	*left(t_data *game)
{
	position_player(game->map, &game->x, &game->y);
	if (game->map[game->x][game->y - 1] == '1')
		return (game);
	if (game->map[game->x][game->y - 1] == '0')
	{
		game->map[game->x][game->y - 1] = 'P';
		game->map[game->x][game->y] = '0';
		game->nb_move++;
		return (game);
	}
	if (game->map[game->x][game->y - 1] == 'E')
	{
		if (coin_count(game->map) == 0)
		{
			game->nb_move++;
			close_image(game);
			exit(0);
		}
		else
			return (game);
	}
	left2(game);
	return (game);
}
