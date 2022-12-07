/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:35:16 by amuller           #+#    #+#             */
/*   Updated: 2022/12/07 12:08:14 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env_path(void)
{
	int	i;

	i = 0;
	while (ft_strncmp(environ[i], "PATH=", 5))
		i++;
	return (environ[i] + 5);
}

char	*get_command_path(char *env_p, char **command_split)
{
	char	**paths;
	char	*cmd;
	int		i;

	i = -1;
	paths = ft_split(env_p, ':');
	if (!paths)
		(put_error(strerror(ENOMEM), NULL, ENOMEM), exit(ENOMEM));
	while (paths[++i])
	{
		cmd = ft_strjoin_all(3, paths[i], "/", command_split[0]);
		if (!cmd)
			(put_error(strerror(ENOMEM), NULL, ENOMEM), exit(ENOMEM));
		if (!access(cmd, X_OK))
			return (ft_free_tab(paths), cmd);
		free(cmd);
	}
	put_error(ERR_CMD, command_split[0], 0);
	(ft_free_tab(paths), ft_free_tab(command_split), exit(127));
	return (NULL);
}
