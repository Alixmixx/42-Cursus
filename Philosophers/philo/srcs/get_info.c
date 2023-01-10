/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:36:47 by amuller           #+#    #+#             */
/*   Updated: 2023/01/04 13:48:30 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_num(char *s)
{
	long	num;
	long	i;
	int		sign;

	num = 0;
	sign = 1;
	i = 0;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	while (s[i])
	{
		num = 10 * num + (s[i] - 48);
		if ((!(s[i] >= '0' && s[i] <= '9')) || num * sign > 2147483647
			|| num * sign < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atoi(const char *s)
{
	long	num;
	long	i;
	int		sign;

	num = 0;
	sign = 1;
	i = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9') && num < 2147483649)
		num = 10 * num + (s[i++] - 48);
	num *= sign;
	if (num > 2147483647)
		return (-1);
	else if (num < -2147483648)
		return (0);
	return (num);
}

static void	verif_values(t_info *info)
{
	if (info->nb_phil > 200)
		exit_error(ERR_MANY_PHI, NULL, ERROR);
	if (info->nb_phil <= 0)
		exit_error(ERR_NO_PHI, NULL, ERROR);
	if (info->time_to_die < 60)
		exit_error(ERR_DIE, NULL, ERROR);
	if (info->time_to_eat < 60)
		exit_error(ERR_EAT, NULL, ERROR);
	if (info->time_to_sleep < 60)
		exit_error(ERR_SLEEP, NULL, ERROR);
	if (info->nb_time_eat == 0)
		exit_error(ERR_TIME_EAT, NULL, ERROR);
}

void	struct_init(t_info *info, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (!ft_is_num(av[i]))
			exit_error(ERR_AV, av[i], ERROR);
	info->nb_phil = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->nb_time_eat = ft_atoi(av[5]);
	else
		info->nb_time_eat = -1;
	verif_values(info);
}
