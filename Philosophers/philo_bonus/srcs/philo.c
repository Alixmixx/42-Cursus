/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:21:24 by amuller           #+#    #+#             */
/*   Updated: 2023/01/03 14:28:57 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_print(t_philo *philo, t_info *info, char *s)
{
	if (!info->dead)
	{
		sem_wait(info->print);
		printf("%ld ", get_time() - info->start_time);
		printf(" %d ", philo->id + 1);
		printf("%s\n", s);
		sem_post(info->print);
	}
}

static void	philo_eat(t_philo *philo, t_info *info)
{
	if (info->dead)
		return ;
	philo_print(philo, info, EAT);
	philo->last_meal = get_time();
	while (!info->dead)
	{
		if (get_time() - philo->last_meal >= info->time_to_eat)
			break ;
		usleep(500);
	}
	sem_post(info->forks);
	sem_post(info->forks);
	philo->nb_meal++;
}

static void	philo_sleep(t_philo *philo, t_info *info)
{
	size_t	sleep_start;

	if (info->dead)
		return ;
	philo_print(philo, info, SLEEP);
	sleep_start = get_time();
	while (!info->dead)
	{
		if (get_time() - sleep_start >= info->time_to_sleep)
			break ;
		usleep(500);
	}
}

static void	philo_get_forks(t_philo *philo, t_info *info)
{
	if (info->dead)
		return ;
	sem_wait(philo->info->forks);
	philo_print(philo, info, FORK);
	sem_wait(philo->info->forks);
	philo_print(philo, info, FORK);
	philo_eat(philo, info);
}

void	philo_action(t_info *info, t_philo *philo)
{
	if (philo->id % 2)
		usleep(10000);
	while (!info->dead)
	{
		philo_get_forks(philo, info);
		philo_sleep(philo, info);
		philo_print(philo, info, THINK);
		usleep(500);
	}
	return ;
}
