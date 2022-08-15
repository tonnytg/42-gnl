#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// conta quantas letras tem uma palavra
int		ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// concatena as letras
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

char *get_next_line(int fd)
{
	char buff[BUFFER_SIZE];
	char *word;
	int i;
	int bytes_transfer;
	int bytes_read;

	bytes_transfer = BUFFER_SIZE;
	i = 0;
	word = "";
	while( (bytes_read = read(fd, &buff, sizeof(buff) - 1)) > 0 )
	{
		i += 1;
		buff[bytes_read] = '\0';
		i = 0;
		word = ft_str_join(word, buff);
		while(buff[i])
		{
			if ( buff[i] ==  '\n' )
				return (word);
			i++;
		}
	}
	return (NULL);
}

int main() {
	char *word;
	int fd;
	int i;

	i = 0;
	fd = open("content.txt", O_RDONLY);
	word = get_next_line(fd);
	while (word != NULL)
	{
		printf("line[%d]: %s",i, word);
		word = get_next_line(fd);
		i++;
	}

	return (0);
}