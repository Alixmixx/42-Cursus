/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:06:55 by amuller           #+#    #+#             */
/*   Updated: 2022/12/03 19:37:16 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*create_tab(char **av, int len)
{
	int	*tab;
	int	i;

	i = 0;
	if (!len)
		return (NULL);
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	while (i < len)
	{
		if (!ft_num(av[i]))
			return (free(tab), NULL);
		tab[i] = ft_atoi(av[i]);
		i++;
	}
	return (tab);
}

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
