// Para copilar
// cc -g3 main2.c -D BUFSIZE=2 && ./a.out
// valgrind --leak-check=full --track-origins=yes -s ./a.out -> Para validar

// O que espero desse arquivo?
// Conseguir obter uma linha

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

static char *ft_strjoin(char *s1, char *s2)
{
	char *result;
	int i;
	int j;

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

static char *ft_save(char *s1)
{
  static char *data = "";
  data = ft_strjoin(data, s1);
  return data;
}

static char *collect_content(fd)
{
	static char *full;
	static char buf[BUFSIZE];
	char *content;
	int i;
	int j;
	int bytes_transfer;
	int bytes_read;

	bytes_transfer = BUFSIZE;
	if (fd == -1)
		return (NULL);
	while ((bytes_read = read(fd, &buf, bytes_transfer)) > 0)
	{
		buf[bytes_read] = '\0';
		content = ft_save(buf);
	}
	return (content);
}

static char *split_str(char *str, char c) {
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	printf("Count Split: %d\n", count );
	return (str);
}

char *get_next_line(int fd)
{
	char *str;
	str = split_str(collect_content(fd), '\n');
	return (str);
}

int main()
{
	int fd;

	fd = open("content.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	return (0);
}
