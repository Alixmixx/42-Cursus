/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:52:26 by amuller           #+#    #+#             */
/*   Updated: 2023/01/03 16:58:19 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*verif_action(void *data)
{
	t_info	*info;
	size_t	starving;
	size_t	stop;

	stop = 0;
	info = (t_info *)data;
	while (1)
	{
		if (info->nb_time_eat != -1 && !stop
			&& info->philo.nb_meal >= info->nb_time_eat)
		{
			philo_print(&info->philo, info, IS_FULL);
			exit(1);
		}
		starving = get_time() - info->philo.last_meal;
		if (starving > info->time_to_die)
		{
			sem_wait(info->print);
			printf("%ld ", get_time() - info->start_time);
			printf(" %d ", info->philo.id + 1);
			(printf("%s\n", DEAD), info->dead = 1);
			exit(0);
		}
		usleep(100);
	}
}
