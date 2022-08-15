#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char buf[1024];
	int fd;
	int i;
	int bytes_transfer;
	int bytes_read;

	bytes_transfer = 1024;

	fd = open("content.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes_read = read(fd, buf, bytes_transfer);
	if (bytes_read > 0)
	{
		printf("bytes_read:%d\n---\n", bytes_read);
		i = 0;
		buf[bytes_read] = 0;
		while(buf[i])
		{
			if (buf[i] == '\n')
				printf("buff[%d] - Ascii[%d] -\t\t Letter[\\n]\n", i, buf[i]);	
			else
				printf("buff[%d] - Ascii[%d] -\t\t Letter[%c]\n", i, buf[i], buf[i]);
			i++;
		}
	}
	return (0);
}
