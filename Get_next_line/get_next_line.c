/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:39:59 by amuller           #+#    #+#             */
/*   Updated: 2022/11/13 00:08:04 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *buf, int fd, ssize_t *needle)
{
	ssize_t	i;

	i = -1;
	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (!buf)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
	}
	while (++i <= BUFFER_SIZE)
		buf[i] = 0;
	*needle = read(fd, buf, BUFFER_SIZE);
	if (*needle <= 0)
		return (free(buf), NULL);
	return (buf);
}

char	*ft_realloc(char *line, char *buf)
{
	char	*join;
	ssize_t	len;
	ssize_t	len_buf;

	len = ft_next_newline(buf);
	len_buf = ft_strlen(buf);
	if (!len)
		len = ft_strlen(buf);
	if (!line)
	{
		join = ft_substr(buf, 0, len);
		buf = ft_memcpy(buf, buf + len, len_buf - len + 1);
	}
	else
		join = ft_join(line, buf, len);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	ssize_t		needle;

	line = NULL;
	needle = 0;
	if (!buf || (buf && !buf[0]))
		buf = ft_read(buf, fd, &needle);
	if (!buf)
		return (NULL);
	while (!ft_next_newline(line) && (needle >= 0))
	{
		line = ft_realloc(line, buf);
		if (!line)
			return (free(buf), NULL);
		if (!ft_strlen(buf) && !ft_next_newline(line))
			buf = ft_read(buf, fd, &needle);
		if (!buf)
			return (line);
	}
	return (line);
}
