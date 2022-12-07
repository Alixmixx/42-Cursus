/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:39:59 by amuller           #+#    #+#             */
/*   Updated: 2022/12/06 20:46:23 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_read(char *buf, int fd, ssize_t *needle)
{
	ssize_t	i;

	i = -1;
	if (fd < 0 || fd > OPEN_MAX)
		return ;
	while (++i <= BUFFER_SIZE)
		buf[i] = 0;
	*needle = read(fd, buf, BUFFER_SIZE);
	if (*needle <= 0)
		buf[0] = 0;
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
		ft_memcpy(buf, buf + len, len_buf - len + 1);
	}
	else
		join = ft_join_gnl(line, buf, len);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		needle;

	line = NULL;
	needle = 0;
	if ((!buf[0]))
	{
		ft_read(buf, fd, &needle);
		if (needle <= 0)
			return (line);
	}
	while (!ft_next_newline(line) && (needle >= 0))
	{
		line = ft_realloc(line, buf);
		if (!line)
			return (NULL);
		if (!ft_strlen(buf) && !ft_next_newline(line))
			ft_read(buf, fd, &needle);
		if (!buf[0])
			return (line);
	}
	return (line);
}
