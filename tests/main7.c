// Para copilar
// cc -g3 main.c -D BUFSIZE=3 && ./a.out
// valgrind --leak-check=full --track-origins=yes -s ./a.out

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
	if (str[i] == '\0')
		return (NULL);
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

char *get_data(int fd, char *data)
{
	char buf[BUFSIZE];
	int bytes_read;
	int bytes_transfer;

	bytes_transfer = BUFSIZE;

	while ( (bytes_read = read(fd, buf, sizeof(buf) - 1)) > 0 )
	{
		buf[bytes_read] = '\0';
		data = ft_str_join(data, buf);
	}
	return (data);
}

char *get_next_line(int fd)
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
