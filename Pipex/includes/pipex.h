/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:24:12 by amuller           #+#    #+#             */
/*   Updated: 2022/12/07 12:27:04 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

# define SUCCESS 0
# define ERROR 1
# define READ 0
# define WRITE 1
# define ERR_USAGE "Usage: ./pipex [INFILE] [COMMAND] ... [COMMAND] [OUTFILE]"
# define ERR_ENV "Environment error"
# define ERR_CMD "Command not found"

// ENVIRONMENT
extern char	**environ;

// PIPES.C
void	exec_command(char *command);
void	fork_process(char *command, int *status);
int		last_fork(char *command, int *status);

// HERE_DOC.C
void	ft_here_doc(char *limiter);
void	ft_here_doc_child(char *limiter, int fd[2]);

// UTILS.C
char	*get_env_path(void);
char	*get_command_path(char *env_p, char **command_split);

// FREE.C
char	**ft_free_tab(char **tab);

// ERROR.C
int		check_environment(void);
int		putstr_error(char *error);
void	shell_error(void);
void	msg_error(char *error, int ret);
void	put_error(char *error, char *file, int ret);

#endif
