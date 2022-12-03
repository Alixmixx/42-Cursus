/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:09:12 by amuller           #+#    #+#             */
/*   Updated: 2022/11/28 14:21:00 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	split_sort(t_stack **a, t_stack **b, t_info *data)
{
	while (*a)
	{
		if ((*a)->key <= data->num + data->chunk)
		{
			(ft_printf("pb\n"), push(a, b));
			data->num++;
			if ((*b)->key < data->num)
			{
				if ((*a) && (*a)->key > data->num + data->chunk)
					(ft_printf("rr\n"), rotate(a), rotate(b));
				else
					(ft_printf("rb\n"), rotate(b));
			}
		}
		else
			(ft_printf("ra\n"), rotate(a));
	}
	data->size = data->len;
}

void	sort_back(t_stack **a, t_stack **b, t_info *data)
{
	t_stack	*temp;
	int		i;

	while (*b)
	{
		i = 0;
		temp = *b;
		while (temp && temp->key != data->size && ++i)
			temp = temp->next;
		if (i <= data->size / 2)
		{
			while ((*b)->key != data->size)
				(rotate(b), ft_printf("rb\n"));
			(ft_printf("pa\n"), push(b, a));
		}
		else
		{
			while ((*b)->key != data->size)
				(rev_rotate(b), ft_printf("rrb\n"));
			(ft_printf("pa\n"), push(b, a));
		}
		data->size--;
	}
}
