/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:53:28 by amuller           #+#    #+#             */
/*   Updated: 2022/12/27 19:36:14 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_meal(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&info->plate);
	while (i < info->nb_phil)
	{
		if (philo[i].nb_meal < info->nb_time_eat)
		{
			pthread_mutex_unlock(&info->plate);
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&info->plate);
	pthread_mutex_lock(&info->death);
	info->full = 1;
	pthread_mutex_unlock(&info->death);
}

void	check_death(t_info *info, t_philo *philo)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(&info->death);
		if (info->dead || info->full)
		{
			pthread_mutex_unlock(&info->death);
			break ;
		}
		pthread_mutex_unlock(&info->death);
		if (info->nb_time_eat >= 0)
			check_meal(info, philo);
		i = -1;
		while (++i < info->nb_phil)
		{
			pthread_mutex_lock(&info->plate);
			if (get_time() - philo[i].last_meal > info->time_to_die)
				(philo_print(philo, info, DEAD),
					pthread_mutex_lock(&info->death), info->dead = 1,
					pthread_mutex_unlock(&info->death));
			pthread_mutex_unlock(&info->plate);
		}
		usleep(100);
	}
}
