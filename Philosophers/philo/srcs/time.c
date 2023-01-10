/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:16:10 by amuller           #+#    #+#             */
/*   Updated: 2022/12/22 14:26:19 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;
	size_t			ms;

	if (gettimeofday(&time, NULL) < 0)
		return (0);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}
