/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:09:30 by lseiller          #+#    #+#             */
/*   Updated: 2022/01/20 17:48:19 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strmcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	length;

	length = ft_strlen(dst);
	i = 0;
	while (i < size && src[i + size])
	{
		dst[i] = src[i + size];
		i++;
	}
	while (i < length)
	{
		dst[i] = '\0';
		i++;
	}
}

void	ft_strrcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	while (i < len && src[i + size])
	{
		dst[i] = src[i + size];
		i++;
	}
	dst[i] = '\0';
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	j;

	j = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == j)
			return (&s[i]);
		i++;
	}
	if (j == 0)
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	free(s2);
	return (dest);
}
