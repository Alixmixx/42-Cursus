/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:14:06 by alixmix           #+#    #+#             */
/*   Updated: 2022/12/12 12:29:54 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

static void	player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] == 'P')
			{
				map->p_y = i;
				map->p_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static int	is_closed(t_game *game)
{
	int	x;

	x = 0;
	while (game->map->map[0][x])
	{
		if (game->map->map[0][x] != '1')
		{
			if (game->map->map[0][x] != '\n')
				return (0);
		}
		x++;
	}
	x = 0;
	while (game->map->map[game->map->y - 1][x])
	{
		if (game->map->map[game->map->y - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

static void	map_verif(t_game *game, char *filename, int fd, int y)
{
	int	i;

	i = -1;
	game->map->x = ft_strlen(game->map->map[i + 1]) - 1;
	while (++i < y)
	{
		if (i != game->map->y - 1 && game->map->x
			!= (int)ft_strlen(game->map->map[i]) - 1)
			(free_map(game->map), free(game), close(fd),
				put_error(ERR_MAP, filename, ERROR), exit(ERROR));
		else if (i == game->map->y - 1 && game->map->x
			!= (int)ft_strlen(game->map->map[i]))
			(free_map(game->map), free(game), close(fd),
				put_error(ERR_MAP, filename, ERROR), exit(ERROR));
	}
}

void	map_init(t_game *game, char *filename, int i)
{
	int		fd;
	int		y;

	y = game->map->y;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		(free(game->map->map), free(game),
			put_error(strerror(errno), filename, errno), exit(ERROR));
	while (++i < y)
	{
		game->map->map[i] = get_next_line(fd);
		if (!game->map->map[i])
			(free_map(game->map), free(game), close(fd),
				put_error(strerror(12), NULL, ERROR), exit(ERROR));
	}
	game->map->map[i] = NULL;
	map_verif(game, filename, fd, y);
	if (!is_closed(game))
		(free_map(game->map), free(game), close(fd),
			put_error(ERR_MAP, filename, ERROR), exit(ERROR));
	(close(fd), player_pos(game->map));
}
