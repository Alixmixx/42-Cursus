/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:09:02 by amuller           #+#    #+#             */
/*   Updated: 2022/11/22 14:09:05 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **st1, t_stack **st2)
{
	t_stack	*temp;

	if (is_empty_stack(*st1))
		return ;
	temp = *st1;
	*st1 = (*st1)->next;
	temp->next = *st2;
	*st2 = temp;
}

void	swap(t_stack **st1)
{
	t_stack	*temp;

	temp = (*st1);
	*st1 = (*st1)->next;
	temp->next = (*st1)->next;
	(*st1)->next = temp;
}

void	rotate(t_stack **st1)
{
	t_stack	*temp;
	t_stack	*curr;

	temp = *st1;
	curr = *st1;
	*st1 = (*st1)->next;
	while (curr->next)
		curr = curr->next;
	temp->next = NULL;
	curr->next = temp;
}

void	rev_rotate(t_stack **st1)
{
	t_stack	*curr;
	t_stack	*last;

	curr = *st1;
	while (curr->next)
	{
		last = curr;
		curr = curr->next;
	}
	last->next = NULL;
	curr->next = *st1;
	*st1 = curr;
}
