/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:41:27 by antthoma          #+#    #+#             */
/*   Updated: 2022/08/23 17:27:24 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buff(int fd)
{
	char	*buff;
	char	*slice;
	int		*bytes_transfer;
	int		bytes_read;

	bytes_transfer = malloc(BUFFER_SIZE * sizeof(int *));
	*bytes_transfer = BUFFER_SIZE;
	if (BUFFER_SIZE < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE * sizeof(char *) + 1);
	if (!buff)
		return (NULL);
	bytes_read = read(fd, buff, *bytes_transfer);
	free(bytes_transfer);
	if (bytes_read < 1)
	{
		free(buff);
		return (NULL);
	}
	buff[bytes_read] = '\0';
	slice = strdup(buff);
	free(buff);
	return (slice);
}

char	*build_line(int fd)
{
	static char	*cache;
	static int	j;
	char		*line;
	int			length;
	int			i;

	i = 0;
	line = strdup("");
	while (i != -1)
	{
		if (!cache)
		{
			cache = ft_read_buff(fd);
			if (!cache)
			{
				if (line[0] != '\0')
					return (line);
				free(line);
				return (NULL);
			}
			j = 0;
			if (cache[j] == '\0')
				return (line);
		}
		length = strlen(cache);
		while (j < length)
		{
			if (cache[j] == '\n')
			{
				line = ft_char_append(line, cache[j]);
				break ;
			}
			line = ft_char_append(line, cache[j]);
			j++;
		}
		if (cache[j] == '\n')
		{
			j++;
			break ;
		}
		free(cache);
		cache = NULL;
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = build_line(fd);
	return (line);
}
