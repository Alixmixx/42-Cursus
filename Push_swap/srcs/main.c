/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:08:55 by amuller           #+#    #+#             */
/*   Updated: 2022/11/29 18:05:04 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	data_init(t_info **data, int ac)
{
	(*data)->len = ac;
	(*data)->size = (*data)->len / 2;
	(*data)->num = 0;
	if ((*data)->len >= 36)
		(*data)->chunk = 12 + ((*data)->len / 33);
	else
		(*data)->chunk = (*data)->len / 3;
}

t_info	*init(t_stack **a, t_stack **b, int ac, char **av)
{
	t_info	*data;
	int		i;

	*a = new_stack();
	*b = new_stack();
	data = malloc(sizeof(*data));
	if (!data)
		return (NULL);
	data_init(&data, ac);
	data->tab = create_tab(av, data->len);
	data->sort_tab = create_tab(av, data->len);
	if (!data->tab || !data->sort_tab || check_duplicate(data->tab, data->len))
		return (free(data->tab), free(data->sort_tab), free(data), NULL);
	sort_tab(data->sort_tab, data->len);
	i = ac;
	while (i-- > 0)
	{
		*a = add_stack(*a, data, ft_atoi(av[i]));
		if (!*a)
			return (free(data->tab), free(data->sort_tab), free(data), NULL);
	}
	return (data);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_info	*data;
	char	**tab;

	if (ac < 2)
		return (0);
	else if (ac > 2)
		data = init(&a, &b, ac - 1, av + 1);
	else
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
			return (write(2, "Error\n", 6), -1);
		data = init(&a, &b, ft_tab_len(tab), tab);
		ft_free_tab(tab);
	}
	if (!data)
		return (write(2, "Error\n", 6), -1);
	if (data->len <= 6)
		small_sort(&a, &b, data);
	else if (!is_sorted_stack(a, len_stack(a)) && data->len > 6)
		(split_sort(&a, &b, data), sort_back(&a, &b, data));
	(clear_stack(a), clear_stack(b));
	return (free(data->tab), free(data->sort_tab), free(data), 0);
}
