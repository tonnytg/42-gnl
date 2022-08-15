// Para copilar
<<<<<<< HEAD
// cc -g3 main.c -D BUFSIZE=2 && ./a.out
// valgrind --leak-check=full --track-origins=yes -s ./a.out -> Para validar
=======
// cc -g3 main.c -D BUFSIZE=3 && ./a.out
// valgrind --leak-check=full --track-origins=yes -s ./a.out
>>>>>>> 270faf4de41c640186c15552222fade10f7fbbf0

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <stddef.h>

// conta letras de uma palvra até achar o \n
int		ft_count_word(char *str, int *start) {
=======

int ft_count_word(char *str, int *start) {
>>>>>>> 270faf4de41c640186c15552222fade10f7fbbf0
	int count;
	int i;

	count = 0;
	i = *start;
	while (str[i] != '\n' && str[i] != '\0')
	{
		count++;
		i++;
	}
<<<<<<< HEAD
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
=======
	*start = i + 1;
	return (count);
}

char *ft_str_join(char *s1, char *s2)
{
	char *result;
	int i;
	int j;

	if (!s1 || !s2)
		return (NULL);
	result = malloc((sizeof(s1) + sizeof(s2)) + 1);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		result[j] = s2[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char *ft_split_str(char *str, int *start) {
>>>>>>> 270faf4de41c640186c15552222fade10f7fbbf0
	char *word;
	int count;
	int i;
	int j;

	i = *start;
<<<<<<< HEAD
	if (!str[i])
		return (NULL);
	count = ft_count_word(str, start);
	word = malloc( count * sizeof(char) + 1);
	if (!word)
		return (NULL);
	j = 0;
=======
	j = 0;
	if (str[i] == '\0')
		return (NULL);
	count = ft_count_word(str, start);
	word = malloc( count * sizeof(char) + 1);
>>>>>>> 270faf4de41c640186c15552222fade10f7fbbf0
	while (str[i] != '\n' && str[i] != '\0' )
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

<<<<<<< HEAD
// le todo arquivo e junta as letras.
char	*get_data(int fd, char *data)
{
	char buf[BUFFSIZE];
	int bytes_read;
	int bytes_transfer;

	bytes_transfer = BUFFSIZE;
=======
char *get_data(int fd, char *data)
{
	char buf[BUFSIZE];
	int bytes_read;
	int bytes_transfer;

	bytes_transfer = BUFSIZE;
>>>>>>> 270faf4de41c640186c15552222fade10f7fbbf0

	while ( (bytes_read = read(fd, buf, sizeof(buf) - 1)) > 0 )
	{
		buf[bytes_read] = '\0';
		data = ft_str_join(data, buf);
	}
	return (data);
}

<<<<<<< HEAD
// pega a proxima linha
char	*get_next_line(int fd)
=======
char *get_next_line(int fd)
>>>>>>> 270faf4de41c640186c15552222fade10f7fbbf0
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

<<<<<<< HEAD
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
=======
int main()
{
	int fd;

	fd = open("content.txt", O_RDONLY);

	printf("1- %s\n", get_next_line(fd));
	printf("2- %s\n", get_next_line(fd));
	printf("3- %s\n", get_next_line(fd));	
	printf("4- %s\n", get_next_line(fd));
	printf("5- %s\n", get_next_line(fd));
	printf("6- %s\n", get_next_line(fd));
	printf("7- %s\n", get_next_line(fd));
	printf("8- %s\n", get_next_line(fd));
	printf("9- %s\n", get_next_line(fd));
	printf("10- %s\n", get_next_line(fd));
	printf("11- %s\n", get_next_line(fd));
	printf("12- %s\n", get_next_line(fd));
	return (0);
}
>>>>>>> 270faf4de41c640186c15552222fade10f7fbbf0
