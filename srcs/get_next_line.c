
#include "get_next_line.h"

char	*get_data(int fd, char *data)
{
	char buf[BUFFER_SIZE];
	int bytes_read;
	int bytes_transfer;

	bytes_transfer = BUFFER_SIZE;

	while ( (bytes_read = read(fd, buf, sizeof(buf) - 1)) > 0 )
	{
		buf[bytes_read] = '\0';
		data = ft_str_join(data, buf);
	}
	return (data);
}

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