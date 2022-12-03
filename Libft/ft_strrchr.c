/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:06:49 by amuller           #+#    #+#             */
/*   Updated: 2022/11/08 15:02:14 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*begin;

	begin = s;
	s += ft_strlen(s) + 1;
	while (--s >= begin)
	{
		if (*s == (char)c)
			return ((char *)(s));
	}
	return (NULL);
}
