// Para copilar
// cc -g3 main2.c -D BUFSIZE=2 && ./a.out


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	char buf[BUFSIZE];
	int fd;
	int i;
	int bytes_transfer;
	int bytes_read;

	bytes_transfer = BUFSIZE;

	fd = open("content.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((bytes_read = read(fd, buf, bytes_transfer)) > 0)
	{
		buf[bytes_read] = '\0';
		printf("%s", buf);
	}

	return (0);
}
