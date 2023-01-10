/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:11:08 by amuller           #+#    #+#             */
/*   Updated: 2023/01/03 18:18:55 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philo(t_info *info, pid_t *philos)
{
	int	i;
	int	status;

	sem_unlink(FORKS_SEM);
	sem_unlink(PRINT_SEM);
	info->forks = sem_open(FORKS_SEM, O_CREAT, 0664, info->nb_phil);
	info->print = sem_open(PRINT_SEM, O_CREAT, 0664, 1);
	info->start_time = get_time();
	if (philo_fork(info, philos))
		return (ERROR);
	waitpid(-1, &status, 0);
	if (WIFEXITED(status) && !WEXITSTATUS(status))
	{
		i = -1;
		while (++i < info->nb_phil)
			kill(philos[i], SIGKILL);
	}
	else
	{
		i = -1;
		while (++i < info->nb_phil)
			waitpid(philos[i], &status, 0);
	}
	return (0);
}
