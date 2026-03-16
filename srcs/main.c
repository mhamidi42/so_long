/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:31:20 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 15:03:32 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	info;

	if (argc != 2)
		return (0);
	info.map = getting_map(argv[1]);
	if (info.map == NULL)
		return (0);
	if (map_parsing(info.map) == 1)
	{
		ft_putendl_fd("Error during parsing", 2);
		free_tab(info.map);
		return (0);
	}
	else
		game_on(info.map);
	return (0);
}
