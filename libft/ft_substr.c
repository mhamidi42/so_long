/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:19:10 by mhamidi           #+#    #+#             */
/*   Updated: 2023/11/22 18:19:12 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;
	unsigned int	j;
	size_t			k;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	k = ft_strlen(s + start);
	if (len > k)
		len = k;
	dest = malloc ((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	j = start;
	while (s[j] && i < len)
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_substr("Hello", 2, 7));
// 	return (0);
// }
