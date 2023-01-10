/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:21:24 by amuller           #+#    #+#             */
/*   Updated: 2023/01/09 13:01:23 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, t_info *info, char *s)
{
	pthread_mutex_lock(&info->print);
	pthread_mutex_lock(&info->death);
	if (!info->dead && !info->full)
	{
		printf("%ld ", get_time() - info->start_time);
		printf(" %d ", philo->id + 1);
		printf("%s\n", s);
	}
	pthread_mutex_unlock(&info->death);
	pthread_mutex_unlock(&info->print);
}

static void	philo_eat(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->plate);
	philo_print(philo, info, EAT);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&info->plate);
	while (1)
	{
		pthread_mutex_lock(&info->death);
		if (info->dead || info->full)
		{
			pthread_mutex_unlock(&info->death);
			break ;
		}
		pthread_mutex_unlock(&info->death);
		if (get_time() - philo->last_meal >= info->time_to_eat)
			break ;
		usleep(500);
	}
	pthread_mutex_lock(&info->plate);
	philo->nb_meal++;
	pthread_mutex_unlock(&info->plate);
}

static void	philo_sleep(t_philo *philo, t_info *info)
{
	size_t	sleep_start;

	philo_print(philo, info, SLEEP);
	sleep_start = get_time();
	while (1)
	{
		pthread_mutex_lock(&info->death);
		if (info->dead || info->full)
		{
			pthread_mutex_unlock(&info->death);
			break ;
		}
		pthread_mutex_unlock(&info->death);
		if (get_time() - sleep_start >= info->time_to_sleep)
			break ;
		usleep(500);
	}
}

static int	philo_get_forks(t_philo *philo, t_info *info)
{
	if (philo->id % 2)
		pthread_mutex_lock(&info->forks[philo->left_fork]);
	else
		pthread_mutex_lock(&info->forks[philo->right_fork]);
	philo_print(philo, info, FORK);
	if (info->nb_phil < 2)
	{
		pthread_mutex_unlock(&(philo->info->forks[philo->left_fork]));
		return (1);
	}
	if (philo->id % 2)
		pthread_mutex_lock(&info->forks[philo->right_fork]);
	else
		pthread_mutex_lock(&info->forks[philo->left_fork]);
	philo_print(philo, info, FORK);
	philo_eat(philo, info);
	if (philo->id % 2)
		(pthread_mutex_unlock(&(philo->info->forks[philo->left_fork])),
			pthread_mutex_unlock(&(philo->info->forks[philo->right_fork])));
	else
		(pthread_mutex_unlock(&(philo->info->forks[philo->right_fork])),
			pthread_mutex_unlock(&(philo->info->forks[philo->left_fork])));
	return (0);
}

void	*philo_action(void *data)
{
	t_philo			*philo;
	t_info			*info;

	philo = (t_philo *)data;
	info = philo->info;
	if (philo->id % 2)
		usleep(10000);
	while (1)
	{
		if (philo_get_forks(philo, info))
			break ;
		philo_sleep(philo, info);
		philo_print(philo, info, THINK);
		pthread_mutex_lock(&info->death);
		if (info->dead || info->full)
		{
			pthread_mutex_unlock(&info->death);
			break ;
		}
		pthread_mutex_unlock(&info->death);
		usleep(100);
	}
	return (NULL);
}
