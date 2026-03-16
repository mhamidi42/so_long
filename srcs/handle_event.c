/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:55:24 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 18:34:48 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_create(t_data info)
{
	t_img	img;
	int		h;
	int		width;

	img.empty = mlx_xpm_file_to_image(info.mlx, "img/empty.xpm", &width, &h);
	img.wall = mlx_xpm_file_to_image(info.mlx, "img/wall.xpm", &width, &h);
	img.player = mlx_xpm_file_to_image(info.mlx, "img/player.xpm", &width, &h);
	img.coin = mlx_xpm_file_to_image(info.mlx, "img/coin.xpm", &width, &h);
	img.exit = mlx_xpm_file_to_image(info.mlx, "img/exit.xpm", &width, &h);
	return (img);
}

void	bring_image(t_data info, t_img img, int i, int j)
{
	if (info.map[i][j] == '0' && img.empty)
		mlx_put_image_to_window
		(info.mlx, info.mlx_win, img.empty, j * 64, i * 64);
	if (info.map[i][j] == '1' && img.wall)
		mlx_put_image_to_window
		(info.mlx, info.mlx_win, img.wall, j * 64, i * 64);
	if (info.map[i][j] == 'P' && img.player)
		mlx_put_image_to_window
		(info.mlx, info.mlx_win, img.player, j * 64, i * 64);
	if (info.map[i][j] == 'E' && img.exit)
		mlx_put_image_to_window
		(info.mlx, info.mlx_win, img.exit, j * 64, i * 64);
	if (info.map[i][j] == 'C' && img.coin)
		mlx_put_image_to_window
		(info.mlx, info.mlx_win, img.coin, j * 64, i * 64);
}

int	show_map(void *infos)
{
	int		i;
	int		j;
	t_data	*game;

	game = (t_data *)infos;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			bring_image(*game, game->img, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_size(char **map, int *i, int *j)
{
	*i = 0;
	while (map[*i] != NULL)
		(*i)++;
	*j = 0;
	while (map[0][*j] != '\0')
		(*j)++;
	*i = *i * 64;
	*j = *j * 64;
}

int	key_event(int keycode, t_data *game)
{
	if (keycode == XK_Escape)
		close_image(game);
	if (keycode == XK_W || keycode == XK_Up)
		game = up(game);
	if (keycode == XK_S || keycode == XK_Down)
		game = down(game);
	if (keycode == XK_D || keycode == XK_Right)
		game = right(game);
	if (keycode == XK_A || keycode == XK_Left)
		game = left(game);
	ft_printf("nombre de mouvements : %d\n", game->nb_move);
	return (0);
}
