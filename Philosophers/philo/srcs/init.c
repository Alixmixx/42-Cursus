/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:11:08 by amuller           #+#    #+#             */
/*   Updated: 2022/12/22 17:27:12 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_info *info)
{
	int	i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->nb_phil);
	if (!info->philo)
		return (ERROR);
	while (i < info->nb_phil)
	{
		info->philo[i].id = i;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->nb_phil;
		info->philo[i].info = info;
		info->philo[i].nb_meal = 0;
		info->philo[i].last_meal = 0;
		i++;
	}
	return (SUCCESS);
}
