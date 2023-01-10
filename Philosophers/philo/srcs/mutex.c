/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:51:34 by amuller           #+#    #+#             */
/*   Updated: 2022/12/22 20:02:48 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_phil)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->death);
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->plate);
	free(info->forks);
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->plate, NULL))
		return (ERROR);
	if (pthread_mutex_init(&info->print, NULL))
		return (ERROR);
	if (pthread_mutex_init(&info->death, NULL))
		return (ERROR);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nb_phil);
	if (!info->forks)
		return (ERROR);
	i = 0;
	while (i < info->nb_phil)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
