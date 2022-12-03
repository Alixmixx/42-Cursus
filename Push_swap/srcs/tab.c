/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:23:26 by amuller           #+#    #+#             */
/*   Updated: 2022/11/28 19:46:37 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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

void	sort_tab(int *tab, int len)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			i = 0;
		}
		else
			i++;
	}
}
