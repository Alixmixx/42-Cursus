/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:23:04 by amuller           #+#    #+#             */
/*   Updated: 2022/11/08 14:08:37 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_1;
	size_t	len_2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, len_1 + 1);
	ft_strlcpy(join + len_1, s2, len_2 + 1);
	return (join);
}
