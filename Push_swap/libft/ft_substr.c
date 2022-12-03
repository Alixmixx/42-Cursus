/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:02:06 by amuller           #+#    #+#             */
/*   Updated: 2022/11/08 16:06:56 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (ft_calloc(1, 1));
	if (len_s < start + len)
		return (ft_substr(s, start, len_s - start));
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	sub = ft_memcpy(sub, s + start, len + 1);
	sub[len] = 0;
	return (sub);
}
