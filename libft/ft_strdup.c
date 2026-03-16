/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:42:08 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/19 12:28:13 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char			*dest;
	size_t			a;

	a = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (a + 1));
	if (!dest)
		return (NULL);
	dest = ft_strcpy(dest, src);
	return (dest);
}

/*
int	main (void)
{
	char *a = "hello worlds";
	char *b;

	b = ft_strdup(a);
	printf("%s\n", b);
	return (0);
}*/