/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:35:10 by mhamidi           #+#    #+#             */
/*   Updated: 2024/04/15 15:24:05 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *stash)
{
	char	*buff;
	int		nb_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nb_read = 1;
	while (!ft_strchr2(stash, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nb_read] = '\0';
		stash = ft_strjoin2(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*extract_new_stash(char *stash)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen2(stash) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (stash[i] != '\0')
		s[j++] = stash[i++];
	s[j] = '\0';
	free(stash);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_line(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	stash = extract_new_stash(stash);
	return (line);
}
