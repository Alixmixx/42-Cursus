/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:25:05 by amuller           #+#    #+#             */
/*   Updated: 2022/12/06 21:36:02 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_here_doc_child(char *limiter, int fd[2])
{
	char	*input;

	if (!limiter)
		put_error(strerror(ENOMEM), NULL, ENOMEM);
	if (close(fd[READ]) < 0)
		(free(limiter), put_error(strerror(errno), NULL, errno), exit(errno));
	ft_printf("heredoc> ");
	input = get_next_line(STDIN_FILENO);
	while (input)
	{
		if (!ft_strcmp(input, limiter))
			(free(limiter), free(input), exit(SUCCESS));
		if (write(fd[WRITE], input, ft_strlen(input)) < 0)
			(free(limiter), free(input),
				put_error(strerror(errno), NULL, errno), exit(errno));
		free(input);
		ft_printf("heredoc> ");
		input = get_next_line(STDIN_FILENO);
	}
	if (close(fd[WRITE]) < 0)
		(free(limiter), free(input),
			put_error(strerror(errno), NULL, errno), exit(errno));
	(free(limiter), free(input));
}

void	ft_here_doc(char *limiter)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) < 0)
		put_error(strerror(errno), NULL, errno);
	pid = fork();
	if (pid < 0)
		put_error(strerror(errno), NULL, errno);
	if (pid > 0)
	{
		if (close(fd[WRITE]) < 0)
			put_error(strerror(errno), NULL, errno);
		if (dup2(fd[READ], STDIN_FILENO) < 0)
			put_error(strerror(errno), NULL, errno);
		if (close(fd[READ]) < 0)
			put_error(strerror(errno), NULL, errno);
		waitpid(pid, &status, 0);
	}
	else
		ft_here_doc_child(ft_strjoin(limiter, "\n"), fd);
}
