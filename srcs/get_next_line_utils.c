#include "get_next_line.h"

int		ft_count_word(char *str, int *start)
{
	int count;
	int i;

	count = 0;
	i = *start;
	while (str[i] != '\n' && str[i] != '\0')
	{
		count++;
		i++;
	}
	if (str[i] != '\0')
		*start = i + 1;
	else
		*start = i;
	return (count);
}

int		ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char	*ft_str_join(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*m;

	if (!s1 || !s2)
		return (NULL);
	m = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
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
	return (m);
}

char	*ft_split_str(char *str, int *start)
{
	char *word;
	int count;
	int i;
	int j;

	i = *start;
	if (!str[i])
		return (NULL);
	count = ft_count_word(str, start);
	word = malloc( count * sizeof(char) + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (str[i] != '\n' && str[i] != '\0' )
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}