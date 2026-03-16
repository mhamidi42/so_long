/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:17:58 by mhamidi           #+#    #+#             */
/*   Updated: 2024/06/11 14:55:02 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '.') && (str[i + 1] == 'b') && (str[i + 2]) == 'e'
			&& (str[i + 3] == 'r') && (str[i + 4]) == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	**mapping_size(int fd)
{
	char	*str;
	int		size_fd;
	char	**map;

	size_fd = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		size_fd++;
		str = get_next_line(fd);
	}
	if (size_fd == 0)
		return (NULL);
	map = malloc((size_fd + 1) * sizeof(char *));
	return (map);
}

char	**put_map(int fd, char **map)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		str[ft_strlen(str) - 1] = '\0';
		map[i] = str;
		str = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**getting_map(char *argv)
{
	int		fd;
	char	**map;

	getting_map2(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (NULL);
	}
	map = mapping_size(fd);
	if (map == NULL)
		exit(EXIT_FAILURE);
	close(fd);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		ft_putstr_fd("map not found\n", 2);
		return (NULL);
	}
	map = put_map(fd, map);
	close(fd);
	return (map);
}

int	getting_map2(char *argv)
{
	if (check_ber(argv) == (0))
	{
		ft_putendl_fd ("mauvaise extension .ber", 2);
		return (0);
	}
	return (1);
}
