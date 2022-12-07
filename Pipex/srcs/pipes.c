/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:26:53 by amuller           #+#    #+#             */
/*   Updated: 2022/12/07 14:03:23 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(char *command)
{
	char	**command_split;
	char	*command_path;
	char	*env_path;

	env_path = get_env_path();
	command_split = ft_split(command, ' ');
	if (!command_split)
		put_error(strerror(ENOMEM), NULL, ENOMEM);
	if (command[0] == '/' || command[0] == '.' || command[0] == '~')
		command_path = command;
	else
		command_path = get_command_path(env_path, command_split);
	if (!command_path)
		(ft_free_tab(command_split), put_error(strerror(ENOMEM), NULL, ENOMEM));
	if (command_path && command_split)
		execve(command_path, command_split, environ);
	put_error(ERR_CMD, command, 1);
}

void	fork_process(char *command, int *status)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		put_error(strerror(errno), NULL, errno);
	pid = fork();
	if (pid < 0)
		put_error(strerror(errno), NULL, errno);
	if (!pid)
	{
		if (close(fd[READ]) < 0)
			put_error(strerror(errno), NULL, errno);
		if (dup2(fd[WRITE], STDOUT_FILENO) < 0)
			put_error(strerror(errno), NULL, errno);
		if (close(fd[WRITE]) < 0)
			put_error(strerror(errno), NULL, errno);
		exec_command(command);
	}
	if (close(fd[WRITE]) < 0)
		put_error(strerror(errno), NULL, errno);
	if (dup2(fd[READ], STDIN_FILENO) < 0)
		put_error(strerror(errno), NULL, errno);
	if (close(fd[READ]) < 0)
		put_error(strerror(errno), NULL, errno);
	waitpid(pid, status, WNOHANG);
}

int	last_fork(char *command, int *status)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		put_error(strerror(errno), NULL, errno);
	if (!pid)
		exec_command(command);
	waitpid(pid, status, 0);
	if (WIFEXITED(*status))
		return (WEXITSTATUS(*status));
	return (ERROR);
}
