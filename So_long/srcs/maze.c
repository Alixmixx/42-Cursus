/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:10:25 by amuller           #+#    #+#             */
/*   Updated: 2022/12/09 16:34:43 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**free_dup(char **dup)
{
	int	i;

	i = 0;
	while (dup[i])
	{
		free(dup[i]);
		i++;
	}
	free(dup);
	return (NULL);
}

static char	**dup_map(t_map *map)
{
	char	**dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(*dup) * (map->y + 1));
	if (!dup)
		return (NULL);
	while (i < map->y)
	{
		dup[i] = ft_strdup(map->map[i]);
		if (!dup[i])
			return (free_dup(dup));
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static int	recursive_maze(char **map, char goal, int x, int y)
{
	if (map[y][x] == goal)
		return (1);
	if (map[y][x] == '1')
		return (0);
	map[y][x] = '1';
	if (recursive_maze(map, goal, x - 1, y))
		return (1);
	if (recursive_maze(map, goal, x, y - 1))
		return (2);
	if (recursive_maze(map, goal, x + 1, y))
		return (3);
	if (recursive_maze(map, goal, x, y + 1))
		return (4);
	return (0);
}

int	maze_solver(t_map *map, char goal, int x, int y)
{
	char	**dup;
	int		direc;

	dup = dup_map(map);
	if (!dup)
		return (0);
	direc = recursive_maze(dup, goal, x, y);
	free_dup(dup);
	return (direc);
}
