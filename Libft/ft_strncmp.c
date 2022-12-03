/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:23:15 by amuller           #+#    #+#             */
/*   Updated: 2022/11/07 20:04:23 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (!len)
		return (0);
	while (s1[i] == s2[i] && (s1[i] && s2[i]) && (i < len - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
