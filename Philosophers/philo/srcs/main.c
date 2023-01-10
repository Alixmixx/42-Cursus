/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:06 by amuller           #+#    #+#             */
/*   Updated: 2022/12/22 17:28:57 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (!*environ)
		exit_error(ERR_ENV, NULL, ERROR);
	if (ac < 5 || ac > 6)
		exit_error(ERR_ARG, NULL, ERROR);
	memset(&info, 0, sizeof(info));
	struct_init(&info, ac, av);
	if (init_mutex(&info))
		(destroy_mutex(&info), exit_error(strerror(ENOMEM), NULL, ERROR));
	if (init_philo(&info))
		(destroy_mutex(&info), exit_error(strerror(ENOMEM), NULL, ERROR));
	thread_create_philo(&info, info.philo);
	destroy_mutex(&info);
	free(info.philo);
	return (0);
}
