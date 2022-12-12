/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:12:05 by amuller           #+#    #+#             */
/*   Updated: 2022/12/10 23:34:20 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_line(t_checker *checker, char *line)
{
	int	i;
	int	nl;

	nl = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			checker->ply++;
		else if (line[i] == 'E')
			checker->exit++;
		else if (line[i] == 'C')
			checker->item++;
		else if (line[i] == '\n')
		{
			checker->newline++;
			nl++;
		}
		else if (line[i] != 'G' && line[i] != '0' && line[i] != '1')
			return (ERROR);
		i++;
	}
	if (checker->x - !nl != i || line[0] != '1' || line[i - 2] != '1')
		return (ERROR);
	return (SUCCESS);
}

static void	is_border(t_checker *checker, char *line)
{
	if (!line)
		return ;
	while (*line)
	{
		if (*line != '1' && *line != '\n')
			return ;
		line++;
	}
	checker->border++;
}

static void	check_filename(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i < 4)
		put_error(ERR_MAP, filename, ERROR);
	if (ft_strcmp(filename + i - 4, ".ber") != 0)
		put_error(ERR_MAP, filename, ERROR);
}

int	map_checker(char *filename)
{
	t_checker	checker;
	int			fd;
	char		*str;

	check_filename(filename);
	(ft_bzero(&checker, sizeof(checker)), fd = open(filename, O_RDONLY));
	if (fd < 0)
		put_error(strerror(errno), filename, errno);
	str = get_next_line(fd);
	(is_border(&checker, str), checker.x = ft_strlen(str));
	while (str)
	{
		if (check_line(&checker, str))
			(free(str), close(fd), put_error(ERR_MAP, filename, 1), exit(1));
		(free(str), checker.y++);
		str = get_next_line(fd);
		is_border(&checker, str);
		if (checker.border < 2 && !str)
			(free(str), close(fd), put_error(ERR_MAP, filename, ERROR));
	}
	close(fd);
	if (checker.x < 3 || checker.y < 3 || checker.exit != 1 || checker.ply != 1
		|| checker.item < 1 || checker.newline != checker.y - 1)
		put_error(ERR_MAP, filename, ERROR);
	return (checker.y);
}
