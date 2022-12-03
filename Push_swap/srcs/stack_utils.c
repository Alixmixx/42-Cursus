/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:21:53 by amuller           #+#    #+#             */
/*   Updated: 2022/11/28 14:46:50 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*add_stack(t_stack *st, t_info *data, int x)
{
	t_stack	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (clear_stack(st), NULL);
	elem->value = x;
	elem->key = get_key(data, x);
	elem->next = st;
	return (elem);
}

t_stack	*pop_stack(t_stack *st)
{
	t_stack	*elem;

	if (is_empty_stack(st))
		return (new_stack());
	elem = st->next;
	free(st);
	return (elem);
}

int	is_rev_sorted_stack(t_stack *st1, int len)
{
	int	value;
	int	i;

	i = 0;
	if (!st1)
		return (0);
	while (i < len - 1)
	{
		value = st1->value;
		st1 = st1->next;
		if (!st1)
			return (0);
		if (value < st1->value)
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_stack(t_stack *st1, int len)
{
	int	value;
	int	i;

	i = 0;
	if (!st1)
		return (0);
	while (i < len - 1)
	{
		value = st1->value;
		st1 = st1->next;
		if (!st1)
			return (0);
		if (value > st1->value)
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
