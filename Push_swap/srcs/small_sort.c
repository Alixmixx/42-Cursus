/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:20:17 by amuller           #+#    #+#             */
/*   Updated: 2022/11/29 18:13:30 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	small_sort(t_stack **a, t_stack **b, t_info *data)
{
	if (is_sorted_stack(*a, len_stack(*a)))
		return ;
	if (data->len <= 3)
		sort_3(a);
	else if (data->len <= 6)
	{
		push_smaller(a, b, data);
		sort_3(a);
		rev_sort_3(b);
		while (len_stack(*b))
			(ft_printf("pa\n"), push(b, a));
	}
}

void	rev_sort_3(t_stack **b)
{
	int		one;
	int		two;
	int		three;

	if (len_stack(*b) == 2)
		if (is_sorted_stack(*b, 2))
			(ft_printf("sb\n"), swap(b));
	if (is_rev_sorted_stack(*b, len_stack(*b)))
		return ;
	one = (*b)->key;
	two = (*b)->next->key;
	three = (*b)->next->next->key;
	if (one > two && one < three && two < three)
		(ft_printf("rrb\n"), rev_rotate(b));
	if (one < two && one < three && two < three)
		(ft_printf("sb\nrrb\n"), swap(b), rev_rotate(b));
	if (one > two && one > three && two < three)
		(ft_printf("sb\nrb\n"), swap(b), rotate(b));
	if (one < two && one < three && two > three)
		(ft_printf("rb\n"), rotate(b));
	if (one < two && one > three && two > three)
		(ft_printf("sb\n"), swap(b));
}

void	sort_3(t_stack **a)
{
	int		one;
	int		two;
	int		three;

	if (len_stack(*a) == 2)
		if (is_rev_sorted_stack(*a, 2))
			(ft_printf("sa\n"), swap(a));
	if (is_sorted_stack(*a, len_stack(*a)))
		return ;
	one = (*a)->key;
	two = (*a)->next->key;
	three = (*a)->next->next->key;
	if (one > two && one < three && two < three)
		(ft_printf("sa\n"), swap(a));
	if (one > two && one > three && two > three)
		(ft_printf("sa\nrra\n"), swap(a), rev_rotate(a));
	if (one > two && one > three && two < three)
		(ft_printf("ra\n"), rotate(a));
	if (one < two && one < three && two > three)
		(ft_printf("sa\nra\n"), swap(a), rotate(a));
	if (one < two && one > three && two > three)
		(ft_printf("rra\n"), rev_rotate(a));
}

void	get_small_top(t_stack **a, int index)
{
	t_stack	*last;
	t_stack	*first;
	int		i;

	if ((*a)->key < index)
		return ;
	i = 0;
	while (i < len_stack(*a))
	{
		last = stack_at(*a, len_stack(*a) - i);
		first = stack_at(*a, 1 + i);
		i++;
		if (last->key < index || first->key < index)
		{
			if (last->key < index && !(first->key < index))
				i *= -1;
			break ;
		}
	}
	if (i < 0)
		while (i++ < 0)
			(ft_printf("rra\n"), rev_rotate(a));
	else if (i > 0)
		while (--i > 0)
			(ft_printf("ra\n"), rotate(a));
}

void	push_smaller(t_stack **a, t_stack **b, t_info *data)
{
	int	len;

	len = data->len / 2 + len_stack(*a) % 2;
	while (len_stack(*a) > 3)
	{
		get_small_top(a, len);
		(ft_printf("pb\n"), push(a, b));
	}
}
