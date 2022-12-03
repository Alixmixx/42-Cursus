/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:09:17 by amuller           #+#    #+#             */
/*   Updated: 2022/11/28 14:42:55 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_stack(void)
{
	return (NULL);
}

int	is_empty_stack(t_stack *st)
{
	if (!st)
		return (1);
	return (0);
}

int	len_stack(t_stack *st)
{
	int	i;

	i = 0;
	while (!is_empty_stack(st))
	{
		i++;
		st = st->next;
	}
	return (i);
}

t_stack	*stack_last(t_stack *st)
{
	if (!st)
		return (NULL);
	while (st->next)
		st = st->next;
	return (st);
}

t_stack	*stack_at(t_stack *st, int x)
{
	int	i;

	i = 1;
	if (!st)
		return (0);
	while (st && i < x)
	{
		st = st->next;
		i++;
	}
	return (st);
}
