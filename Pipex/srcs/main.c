/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:43:05 by amuller           #+#    #+#             */
/*   Updated: 2022/12/07 23:25:35 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_fds(char **av, int fd[2])
{
	fd[READ] = open(av[1], O_RDONLY);
	if (fd[READ] < 0)
	{
		put_error(strerror(errno), av[1], 0);
		fd[READ] = open(".error_fd", O_CREAT | O_RDWR | O_TRUNC, 0000644);
		if (fd[READ] < 0)
			put_error(strerror(errno), NULL, errno);
		if (dup2(fd[READ], STDIN_FILENO) < 0)
			put_error(strerror(errno), NULL, errno);
	}
	else if (dup2(fd[READ], STDIN_FILENO) < 0)
		put_error(strerror(errno), NULL, errno);
	if (close(fd[READ]) < 0)
		put_error(strerror(errno), NULL, errno);
}

int	main(int ac, char **av)
{
	int				status;
	int				fd[2];
	int				i;

	i = 1;
	status = 0;
	if (!check_environment())
		(putstr_error(ERR_ENV), exit(ERROR));
	if ((ac < 6 && !ft_strcmp(av[1], "here_doc")) || ac < 5)
		put_error(strerror(EINVAL), ERR_USAGE, ENOENT);
	if (!ft_strcmp(av[1], "here_doc"))
	{
		(ft_here_doc(av[2]), i++);
		fd[WRITE] = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0000644);
	}
	else
	{
		redirect_fds(av, fd);
		fd[WRITE] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	}
	if (fd[WRITE] < 0)
		put_error(strerror(errno), av[ac - 1], errno);
	while (++i < ac - 2)
		fork_process(av[i], &status);
	if (dup2(fd[WRITE], STDOUT_FILENO) < 0)
		put_error(strerror(errno), NULL, errno);
	if (!access(".error_fd", F_OK) && unlink(".error_fd") < 0)
		put_error(strerror(errno), NULL, errno);
	status = last_fork(av[i], &status);
	return (status);
}
