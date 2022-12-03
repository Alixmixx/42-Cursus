/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:09:24 by amuller           #+#    #+#             */
/*   Updated: 2022/11/29 16:07:34 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_num(char *s)
{
	long	num;
	long	i;
	int		sign;

	num = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
			sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		num = 10 * num + (s[i] - 48);
		if (!ft_isdigit(s[i]) || num * sign > 2147483647
			|| num * sign < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[j] == tab[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_key(t_info *data, int value)
{
	int	i;

	i = 0;
	while (data->sort_tab[i] != value)
		i++;
	return (i + 1);
}
