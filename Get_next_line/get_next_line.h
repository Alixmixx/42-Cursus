/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:40:14 by amuller           #+#    #+#             */
/*   Updated: 2022/11/11 14:53:15 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 1048576
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_realloc(char *line, char *buf);
char	*ft_read(char *buf, int fd, ssize_t *needle);

char	*ft_join(char *line, char *buf, size_t len);
char	*get_next_line(int fd);
ssize_t	ft_next_newline(const char *s);
ssize_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, ssize_t size);
char	*ft_substr(char const *s, unsigned int start, ssize_t len);

#endif