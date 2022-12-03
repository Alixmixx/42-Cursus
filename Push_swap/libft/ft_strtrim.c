/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:32:42 by amuller           #+#    #+#             */
/*   Updated: 2022/11/08 14:18:50 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	offset;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	offset = 0;
	len_s1 = ft_strlen(s1) - 1;
	while (s1[offset] && ft_isset(s1[offset], set))
		offset++;
	if (len_s1 < offset)
		return (ft_calloc(1, 1));
	while (s1[len_s1] && ft_isset(s1[len_s1], set))
		len_s1--;
	return (ft_substr(s1, offset, len_s1 - offset + 1));
}
