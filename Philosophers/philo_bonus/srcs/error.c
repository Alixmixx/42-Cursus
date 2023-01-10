/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:10:11 by amuller           #+#    #+#             */
/*   Updated: 2022/12/18 20:34:20 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static int	putstr_error(char *error)
{
	write(2, error, ft_strlen(error));
	return (ERROR);
}

void	exit_error(char *error, char *file, int ret)
{
	putstr_error(error);
	if (file)
	{
		putstr_error(": ");
		putstr_error(file);
	}
	putstr_error("\n");
	if (!ret)
		return ;
	exit (ret);
}
