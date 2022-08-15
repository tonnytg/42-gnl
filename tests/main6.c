// Para copilar
// cc -g3 main.c -D BUFSIZE=2 && ./a.out
// valgrind --leak-check=full --track-origins=yes -s ./a.out -> Para validar

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int ft_count_word(char *str, int *start) {
	int count;
	int i;

	count = 0;
	i = *start;
	while (str[i] != '\n' && str[i] != '\0')
	{
		count++;
		i++;
	}
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
	char *word;
	int count;
	int i;
	int j;

	i = *start;
	j = 0;
	count = ft_count_word(str, start);
	word = malloc( count * sizeof(char) + 1);
	while (str[i] != '\n' && str[i] != '\0' )
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char *ft_call_word(char *str)
{
	char *word;
	static int y;

	if (str[y] == '\0')
		return (NULL);
	word = ft_split_str(str, &y);
	return (word);
}

char *ft_save_str(char *s1)
{
	static char *data;

	if (!data)
		data = "";
	data = ft_str_join(data, s1);
	return (data);
}

char *ft_get_data(int fd, char *data)
{
	char 	*word;
	char	buf[BUFSIZE];
	int		bytes_transfer;
	int		bytes_read;

	if (fd == -1)
		return (NULL);
	bytes_transfer = BUFSIZE;
	bytes_read = read(fd, &buf, bytes_transfer);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		word = ft_save_str(buf);
		bytes_read = read(fd, &buf, bytes_transfer);
	}
	return (word);
}

static char *get_next_line(int fd)
{
	static char *data; // armazena toda a informação dos caracteres lidos
	static int start;  // ponto de partida ao procurar outra palavra, até achar \n 
	char *word;		   // armazena a palavra obtida entre o start e \n

	if (!data) // trava de segurança se o data não tiver sido inicializado
		data = "";
	word = ft_get_data(fd, data);
	return (ft_call_word(word));
}

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
	return (0);
}