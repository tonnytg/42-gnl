/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:41:34 by antthoma          #+#    #+#             */
/*   Updated: 2022/08/23 14:31:30 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

size_t	ft_strlen(char const *str);
char	*ft_str_join(char *s1, char *s2);
char	*ft_char_append(char *s1, char c);
char	*get_next_line(int fd);
char	*str_copy(char const *str);
int		check_breakline(char const *str);
char	*ft_parse(char *str);

#endif
