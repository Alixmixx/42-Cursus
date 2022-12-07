/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:05:45 by amuller           #+#    #+#             */
/*   Updated: 2022/11/07 23:36:05 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)p)[i] = (unsigned char)c;
		i++;
	}
	return (p);
}
