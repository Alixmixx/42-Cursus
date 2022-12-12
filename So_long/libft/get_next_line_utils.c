/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:00:48 by amuller           #+#    #+#             */
/*   Updated: 2022/11/23 13:38:57 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_gnl(char *line, char *buf, size_t len)
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
