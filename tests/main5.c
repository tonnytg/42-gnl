#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int CountWord(char *str, int *start) {
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

char *SplitStr(char *str, int *y) {
  int j;
  int count;
  int x;
  char *word;
  
  j = 0;
  x = *y;
  count = CountWord(str, y);
  word = malloc( count * sizeof(char) + 1);
  while (str[x] != '\n' && str[x] != '\0' )
  {
    word[j] = str[x];
    x++;
    j++;
  }
  word[j] = '\0';
  return (word);
}

char *CallWordInStr(char *str)
{
	static int y;
	char *word;
	word = SplitStr(str, &y);
	//   printf("Word: %s\n", word);
	return(word);
}

// percorre duas strings e adiciona o valor em uma outra, adicionando nulo no final
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

// cache das letras lidas
static char *ft_save(char *s1)
{
  static char *data = "";
  data = ft_strjoin(data, s1);
  return data;
}

// coleta as letras dentro de sua capacidade
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

char *get_next_line(int fd)
{
	char *str;
	str = collect_content(fd);
	str = CallWordInStr(str);
	return (str);
}

int main() {
	int start;
	char *word;
	char *nome="Antonio\nThomacelli\nGomes";
	int fd;


	fd = open("content.txt", O_RDONLY);
	printf("1 - %s\n", get_next_line(fd));
	printf("2 - %s\n", get_next_line(fd));

	// CallWordInStr(nome);
	// printf("Proxima palavra\n");
	// CallWordInStr(nome);
	// printf("Proxima palavra\n");
	// CallWordInStr(nome); 
}