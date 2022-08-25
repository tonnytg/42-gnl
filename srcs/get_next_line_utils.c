/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:41:34 by antthoma          #+#    #+#             */
/*   Updated: 2022/08/24 13:54:07 by antthoma         ###   ########.fr       */
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

size_t	ft_strlen(char const *str);
char	*ft_strdup(char *str);
char	*ft_char_append(char *s1, char c);
char	*get_next_line(int fd);
char	*ft_read_buff(int fd);

#endif
