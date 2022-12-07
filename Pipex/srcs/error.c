/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:29:59 by amuller           #+#    #+#             */
/*   Updated: 2022/12/07 12:02:10 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_environment(void)
{
	int	i;
	int	env_size;

	i = 0;
	env_size = 0;
	while (environ[env_size])
		env_size++;
	if (!*environ)
		return (0);
	while (ft_strlen(environ[i]) >= 5 && ft_strncmp(environ[i], "PATH=", 5))
		i++;
	if (i == env_size)
		return (0);
	i = 0;
	while (ft_strlen(environ[i]) >= 6 && ft_strncmp(environ[i], "SHELL=", 6))
		i++;
	if (i == env_size)
		return (0);
	return (1);
}

int	putstr_error(char *error)
{
	write(2, error, ft_strlen(error));
	return (ERROR);
}

void	shell_error(void)
{
	char	**tab;
	int		i;

	i = 0;
	while (ft_strncmp(environ[i], "SHELL=", 6))
		i++;
	tab = ft_split(environ[i] + 6, '/');
	if (!tab)
		(putstr_error(strerror(ENOMEM)), exit(ENOMEM));
	i = 0;
	while (tab[i])
		i++;
	if (i > 0)
		i--;
	putstr_error(tab[i]);
	ft_free_tab(tab);
	putstr_error(": ");
}

void	msg_error(char *error, int ret)
{
	shell_error();
	perror(error);
	if (ret)
		exit(ret);
	exit (ERROR);
}

void	put_error(char *error, char *file, int ret)
{
	shell_error();
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
