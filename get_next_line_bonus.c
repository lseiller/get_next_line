/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:02:31 by lseiller          #+#    #+#             */
/*   Updated: 2022/02/02 17:07:51 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_no_nl(char *buffer)
{
	char		*line;
	size_t		i;
	size_t		size;

	size = ft_strlen(buffer);
	i = 0;
	line = malloc(size + 1);
	if (!line)
		return (NULL);
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*fill_nl(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	size;

	size = ft_strchr(buffer, '\n') - buffer;
	i = 0;
	line = malloc(size + 2);
	if (!line)
		return (NULL);
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	ft_strrcpy(buffer, buffer, size + 1);
	return (line);
}

char	*fill_join(char *line, char *buffer, int fd, int read_value)
{
	char	*line2;

	if (ft_strchr(buffer, '\n') == NULL)
	{
		line2 = fill_no_nl(buffer);
		ft_strmcpy(buffer, buffer, read_value);
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == 0)
		{
			line = ft_strjoin(line, line2);
			*buffer = '\0';
		}
		else if (read_value < 0)
			return (NULL);
		else
			line = fill_join(ft_strjoin(line, line2), buffer, fd, read_value);
	}
	else
	{
		line2 = fill_nl(buffer);
		line = ft_strjoin(line, line2);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[512][BUFFER_SIZE + 1];
	char		*line;
	int			read_value;

	if (fd < 0 || fd > 512)
		return (NULL);
	if (!*(*(buffer + fd)))
		read_value = read(fd, *(buffer + fd), BUFFER_SIZE);
	else
		read_value = 1;
	if (read_value <= 0)
		return (NULL);
	line = malloc(1);
	line[0] = '\0';
	line = fill_join(line, buffer[fd], fd, read_value);
	return (line);
}
