#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// This is a minimal example of how to use the readfile function.
// It reads the file and prints it to stdout.
// You need create a test.txt file with the following content:

int main(){
	char ch;
	int fd;

	fd = open("test.txt", O_RDONLY);
	if(fd == -1){
		printf("Error opening file\n");
		return (1);
	}
	while(read(fd, &ch, 1) != 0){
		printf("%c", ch);
	}
	close(fd);

	return (0);
}
