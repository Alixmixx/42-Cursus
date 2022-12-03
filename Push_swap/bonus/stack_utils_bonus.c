/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:37:30 by amuller           #+#    #+#             */
/*   Updated: 2022/11/28 14:38:17 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"

int	is_sorted_stack(t_stack *st1, int len)
{
	int	value;
	int	i;

	i = 0;
	if (!st1)
		return (0);
	value = st1->value;
	while (i < len - 1)
	{
		st1 = st1->next;
		if (!st1)
			return (0);
		if (value >= st1->value)
			return (0);
		i++;
	}
	return (1);
}

t_stack	*clear_stack(t_stack *st)
{
	if (is_empty_stack(st))
		return (new_stack());
	while (!is_empty_stack(st))
		st = pop_stack(st);
	return (new_stack());
}
