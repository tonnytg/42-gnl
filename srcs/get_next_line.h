#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

// Helper functions
int		ft_count_word(char *str, int *start);
int		ft_strlen(char const *str);
char	*ft_str_join(char const *s1, char const *s2);
char	*ft_split_str(char *str, int *start);
char	*get_data(int fd, char *data);

#endif