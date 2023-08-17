#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_count_word(char *str, int *start);
char	*ft_str_join(char const *s1, char const *s2);
char	*ft_split_str(char *str, int *start);
char	*get_data(int fd, char *data);
char    *ft_read_buff(int fd);
char    *ft_check_cache(char *cache, char *line, int fd, int *x);
char    *ft_strdup(char *str);
size_t  ft_strlen(char const *str);
char    *ft_char_append(char *s1, char c);

#endif