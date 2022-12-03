/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:34:21 by amuller           #+#    #+#             */
/*   Updated: 2022/11/29 01:45:19 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"

int	ft_free(t_stack *a, t_stack *b, t_info *data, int message)
{
	a = clear_stack(a);
	b = clear_stack(b);
	if (data)
	{
		if (data->move)
			free(data->move);
		free(data);
	}
	if (message == 1)
		return (ft_printf("OK\n"), 0);
	else if (message == -1)
		return (ft_printf("KO\n"), 0);
	else
		return (write(2, "Error\n", 6), -1);
}

int	ft_read_move(char *line, t_info *data)
{
	if (!line)
		return (0);
	if (data->move)
		free(data->move);
	data->move = ft_strdup(line);
	free(line);
	if (!data->move)
		return (0);
	return (1);
}

int	ft_make_move(t_stack **a, t_stack **b, t_info *data)
{
	if (!ft_strcmp("pa\n", data->move))
		push(b, a);
	else if (!ft_strcmp("pb\n", data->move))
		push(a, b);
	else if (!ft_strcmp("sa\n", data->move))
		swap(a);
	else if (!ft_strcmp("sb\n", data->move))
		swap(b);
	else if (!ft_strcmp("ss\n", data->move))
		(swap(a), swap(b));
	else if (!ft_strcmp("ra\n", data->move))
		rotate(a);
	else if (!ft_strcmp("rb\n", data->move))
		rotate(b);
	else if (!ft_strcmp("rr\n", data->move))
		(rotate(a), rotate(b));
	else if (!ft_strcmp("rra\n", data->move))
		rev_rotate(a);
	else if (!ft_strcmp("rrb\n", data->move))
		rev_rotate(b);
	else if (!ft_strcmp("rrr\n", data->move))
		(rev_rotate(a), rev_rotate(b));
	else
		return (0);
	return (1);
}

int	ft_check_moves(t_stack *a, t_stack *b, t_info *data)
{
	if (len_stack(a) == data->len && is_sorted_stack(a, len_stack(a))
		&& is_empty_stack(b))
		return (1);
	return (0);
}
