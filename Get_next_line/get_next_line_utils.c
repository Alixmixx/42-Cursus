/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:00:48 by amuller           #+#    #+#             */
/*   Updated: 2022/11/12 23:58:08 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *line, char *buf, size_t len)
{
	char	*join;
	ssize_t	len_line;

	len_line = ft_strlen(line);
	join = malloc((len_line + len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join[len_line + len] = 0;
	join = ft_memcpy(join, line, len_line);
	ft_memcpy(join + len_line, buf, len);
	ft_memcpy(buf, buf + len, ft_strlen(buf) - len + 1);
	buf[BUFFER_SIZE - len] = '\0';
	free(line);
	return (join);
}

ssize_t	ft_next_newline(const char *s)
{
	ssize_t	i;
	ssize_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

ssize_t	ft_strlen(const char *s)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, ssize_t size)
{
	ssize_t	i;

	i = 0;
	if (dest != src)
	{
		while (i < size)
		{
			if (!src)
				((unsigned char *)dest)[i] = 0;
			else
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, ssize_t len)
{
	char	*sub;
	ssize_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (malloc(sizeof(char)));
	if (len_s < start + len)
		return (ft_substr(s, start, len_s - start));
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	sub = ft_memcpy(sub, s + start, len + 1);
	sub[len] = 0;
	return (sub);
}
