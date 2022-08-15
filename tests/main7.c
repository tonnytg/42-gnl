// Para copilar
// cc -g3 main.c -D BUFSIZE=2 && ./a.out
// valgrind --leak-check=full --track-origins=yes -s ./a.out -> Para validar

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

// conta letras de uma palvra até achar o \n
int		ft_count_word(char *str, int *start) {
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

// divide as palavras
char	*ft_split_str(char *str, int *start) {
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

// le todo arquivo e junta as letras.
char	*get_data(int fd, char *data)
{
	char buf[BUFFSIZE];
	int bytes_read;
	int bytes_transfer;

	bytes_transfer = BUFFSIZE;

	while ( (bytes_read = read(fd, buf, sizeof(buf) - 1)) > 0 )
	{
		buf[bytes_read] = '\0';
		data = ft_str_join(data, buf);
	}
	return (data);
}

// pega a proxima linha
char	*get_next_line(int fd)
{
	static char *data;
	static int start;

	if (!data)
	{
		data = "";
		start = 0;
	}
	data = get_data(fd, data);
	return (ft_split_str(data, &start));
}

// main
int main()
{
	int fd;
	char *word;

	fd = open("content.txt", O_RDONLY);

	word = get_next_line(fd);
	while (word != NULL)
	{
		printf("%s\n", word);
		word = get_next_line(fd);
	}
	return (0);
}