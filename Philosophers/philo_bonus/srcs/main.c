/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:06 by amuller           #+#    #+#             */
/*   Updated: 2022/12/28 20:23:22 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_info	info;
	pid_t	*philos;

	if (!*environ)
		exit_error(ERR_ENV, NULL, ERROR);
	if (ac < 5 || ac > 6)
		exit_error(ERR_ARG, NULL, ERROR);
	memset(&info, 0, sizeof(info));
	struct_init(&info, ac, av);
	philos = malloc(sizeof(pid_t) * info.nb_phil);
	if (!philos)
		exit_error(strerror(ENOMEM), NULL, ERROR);
	else
		memset(philos, 0, sizeof(pid_t) * info.nb_phil);
	init_philo(&info, philos);
	sem_close(info.print);
	sem_close(info.forks);
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINT_SEM);
	free(philos);
	return (0);
}
