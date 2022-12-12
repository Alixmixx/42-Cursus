/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:10:11 by amuller           #+#    #+#             */
/*   Updated: 2022/12/09 15:00:16 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	putstr_error(char *error)
{
	write(2, error, ft_strlen(error));
	return (ERROR);
}

void	msg_error(char *error, int ret)
{
	perror(error);
	if (ret)
		exit(ret);
	exit (ERROR);
}

void	put_error(char *error, char *file, int ret)
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
