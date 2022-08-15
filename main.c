#include "./srcs/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int main() {
	char *word;
	int fd;
	int i;

	i = 0;
	fd = open("content.txt", O_RDONLY);
	word = get_next_line(fd);
	while (word != NULL)
	{
		printf("line[%d]: %s\n",i, word);
		word = get_next_line(fd);
		i++;
	}

	return (0);
}
