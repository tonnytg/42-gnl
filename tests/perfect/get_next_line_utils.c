/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:41:41 by antthoma          #+#    #+#             */
/*   Updated: 2022/08/23 17:27:37 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (!str || str[i] != '\0')
		i++;
	return (i);
}

char	*str_copy(char const *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		temp[i] = '\n';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_str_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*m;

	if (!s1 || !s2)
		return (NULL);
	m = malloc((strlen(s1) + strlen(s2)) + 1);
	if (!m)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		m[i++] = s1[j++];
	j = 0;
	while (s2[j])
		m[i++] = s2[j++];
	m[i] = '\0';
	free(s1);
	return (m);
}

char	*ft_char_append(char *s1, char c)
{
	int		i;
	char	*m;

	if (!s1 || !c)
		return (NULL);
	m = malloc((strlen(s1) + sizeof(c)) + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = c;
	i++;
	m[i] = '\0';
	free(s1);
	return (m);
}

int	check_breakline(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_parse(char *str)
{
	char	*line;
	int		i;
	int		length;

	i = 0;
	length = strlen(str);
	line = malloc(strlen(line) + 1);
	if (!line)
		return (NULL);
	{
		if (str[i] != '\n')
		{
			line[i] = str[i];
			i++;
		}
		else
			i = 0;
	}
	return (line);
}
