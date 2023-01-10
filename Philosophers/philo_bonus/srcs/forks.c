/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:51:34 by amuller           #+#    #+#             */
/*   Updated: 2022/12/28 20:17:43 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_fork(t_info *info, pid_t *philos)
{
	int	i;

	i = 0;
	while (i < info->nb_phil)
	{
		info->philo.pid = fork();
		info->philo.info = info;
		info->philo.last_meal = info->start_time;
		if (info->philo.pid < 0)
			return (ERROR);
		if (!info->philo.pid)
		{
			info->philo.id = i;
			pthread_create(&info->philo.verif, NULL, verif_action, info);
			pthread_detach(info->philo.verif);
			philo_action(info, &info->philo);
		}
		philos[i] = info->philo.pid;
		i++;
	}
	return (0);
}
