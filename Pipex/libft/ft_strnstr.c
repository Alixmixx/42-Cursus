/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:04:36 by amuller           #+#    #+#             */
/*   Updated: 2022/11/07 23:43:00 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*find))
		return ((char *)s);
	while (i < len && s[i])
	{
		j = 0;
		while (s[i + j] == find[j] && i + j < len)
		{
			j++;
			if (!find[j])
				return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}
