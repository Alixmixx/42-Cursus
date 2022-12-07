/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:34:51 by amuller           #+#    #+#             */
/*   Updated: 2022/11/08 15:19:19 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s)
	{
		if (*s != c)
		{
			count++;
			s = ft_strchr(s, c);
		}
		else
			s++;
	}
	return (count);
}

static char	**ft_free(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

static size_t	ft_nextc(char const *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (ft_word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = ft_nextc(s, c);
			tab[i] = ft_substr(s, 0, len);
			if (!tab[i])
				return (ft_free(tab));
			i++;
			s += len - 1;
		}
		s++;
	}
	tab[i] = NULL;
	return (tab);
}
