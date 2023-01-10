/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:52:26 by amuller           #+#    #+#             */
/*   Updated: 2023/01/09 12:34:15 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_destroy_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_phil)
	{
		if (pthread_join(info->philo[i].t_id, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	thread_create_philo(t_info *info, t_philo *philo)
{
	int		i;
	void	*copy_philo;

	i = 0;
	info->start_time = get_time();
	while (i < info->nb_phil)
	{
		philo[i].last_meal = info->start_time;
		copy_philo = (void *)&(philo[i]);
		if (pthread_create(&philo[i].t_id, NULL, philo_action, copy_philo))
			return (1);
		i++;
	}
	check_death(info, info->philo);
	thread_destroy_philo(info);
	return (0);
}
