/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:49:29 by amuller           #+#    #+#             */
/*   Updated: 2022/11/08 13:45:42 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	int	size;

	size = 1;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		size;
	long	num;

	size = ft_nb_len(n);
	num = n;
	if (num <= 0)
		num *= -1;
	s = ft_calloc(size, sizeof(char));
	if (!s)
		return (NULL);
	s[--size] = 0;
	if (!num)
		s[--size] = '0';
	while (num)
	{
		s[--size] = (num % 10) + 48;
		num /= 10;
	}
	if (size > 0)
		s[0] = '-';
	return (s);
}
