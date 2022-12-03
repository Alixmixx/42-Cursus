/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:13:27 by amuller           #+#    #+#             */
/*   Updated: 2022/11/29 17:58:45 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"

t_info	*init(t_stack **a, t_stack **b, int ac, char **av)
{
	t_info	*data;
	int		i;

	*a = new_stack();
	*b = new_stack();
	data = malloc(sizeof(*data));
	if (!data)
		return (NULL);
	data->len = ac;
	data->move = NULL;
	i = ac;
	data->tab = create_tab(av, ac);
	if (!data->tab || check_duplicate(data->tab, data->len))
		return (free(data->tab), free(data), NULL);
	while (i-- > 0)
	{
		*a = add_stack(*a, ft_atoi(av[i]));
		if (!*a)
			return (free(data->tab), free(data), NULL);
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
	else if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
			return (write(2, "Error\n", 6), -1);
		data = init(&a, &b, ft_tab_len(tab), tab);
		ft_free_tab(tab);
	}
	else
		data = init(&a, &b, ac - 1, av + 1);
	if (!data)
		return (ft_free(a, b, data, ERROR));
	while (ft_read_move(get_next_line(0), data))
		if (!ft_make_move(&a, &b, data))
			return (free(data->tab), ft_free(a, b, data, ERROR));
	if (ft_check_moves(a, b, data))
		return (free(data->tab), ft_free(a, b, data, OK));
	return (free(data->tab), ft_free(a, b, data, KO));
}
