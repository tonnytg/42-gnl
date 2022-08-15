#include <stdio.h>
#include <string.h>

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

void CallWordInStr(char *str)
{
  static int y;
  char *word;
  word = SplitStr(str, &y);
  printf("Word: %s\n", word);
}

int main() {
  int start;
  char *word;
  char *nome="Antonio\nThomacelli\nGomes";
  
  CallWordInStr(nome);
  printf("Proxima palavra\n");
  CallWordInStr(nome);
  printf("Proxima palavra\n");
  CallWordInStr(nome);  
}
