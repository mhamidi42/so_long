/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_on.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:48:18 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 14:51:16 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_on(char **map)
{
	t_data	game;

	game.map = map;
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		ft_putendl_fd("Error initializing MLX", 2);
		return ;
	}
	map_size(map, &game.x, &game.y);
	game.mlx_win = mlx_new_window(game.mlx, game.y, game.x, "So_long");
	if (game.mlx_win == NULL)
	{
		ft_putendl_fd("Error creating window", 2);
		mlx_destroy_display(game.mlx_win);
		free(game.mlx_win);
		return ;
	}
	game.nb_move = 0;
	game.img = img_create(game);
	mlx_key_hook(game.mlx_win, key_event, &game);
	mlx_hook(game.mlx_win, 17, 0, close_event, &game);
	mlx_loop_hook(game.mlx, show_map, &game);
	mlx_loop(game.mlx);
}
