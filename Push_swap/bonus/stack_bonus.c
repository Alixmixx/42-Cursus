/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:08:35 by amuller           #+#    #+#             */
/*   Updated: 2022/11/29 17:46:03 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"

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

t_stack	*add_stack(t_stack *st, int x)
{
	t_stack	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (clear_stack(st), NULL);
	elem->value = x;
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
