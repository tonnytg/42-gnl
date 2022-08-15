
SRC= "./srcs/"

all: copile

copile:
	cc -g3 main.c $(SRC)get_next_line.c $(SRC)get_next_line.h $(SRC)get_next_line_utils.c -D BUFFER_SIZE=3 && ./a.out

clean:
	rm tests/a.out
	rm srcs/a.out