/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:30:23 by alixmix           #+#    #+#             */
/*   Updated: 2022/12/11 14:39:17 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_obstacle(t_game *game, int x, int y)
{
	if (y % 3 == 0 && x % 3 == 1
		&& x > 2 && y > 2 && game->map->map[y - 1][x] == '1'
		&& game->map->map[y - 2][x] == '1' && game->map->map[y - 1][x - 1] ==
		'1' && game->map->map[y][x - 1] == '1' && game->map->map[y][x - 2] ==
		'1' && game->map->map[y - 1][x - 2] == '1' && y < game->map->y - 2
		&& x < game->map->x - 2 && game->map->map[y - 2][x - 2] == '1')
	{
		print_with_alpha(&game->wall[7], &game->back,
			(x - 2) * 32, (y - 2) * 32);
		x++;
		if (x == game->map->x - 1)
			print_with_alpha(&game->wall[1], &game->back, x * 32, y * 32);
		else if (game->map->map[y][x] == '1')
			print_with_alpha(&game->wall[5], &game->back, x * 32, y * 32);
	}
	else if ((x == 0 || x == game->map->x - 1) && y != game->map->y - 1)
		print_with_alpha(&game->wall[1], &game->back, x * 32, y * 32);
	else if (y == 0 || y == game->map->y - 1)
		print_with_alpha(&game->wall[0], &game->back, x * 32, y * 32);
	else
		print_with_alpha(&game->wall[5], &game->back, x * 32, y * 32);
	return (x);
}

void	load_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			if (game->map->map[y][x] == '1')
				x = load_obstacle(game, x, y);
			x++;
		}
		y++;
	}
}

void	load_back(t_game *game, int y, int x)
{
	while (++y < game->map->y)
	{
		x = -1;
		while (++x < game->map->x)
		{
			if ((x != 0 && y != 0) && (game->map->map[y][x] == '0'
				|| game->map->map[y][x] == 'G'))
				print_with_alpha(&game->tiles[0], &game->back, x * 32, y * 32);
			else if (x != 0 && y != 0 && x != game->map->x - 1)
				print_with_alpha(&game->tiles[1], &game->back, x * 32, y * 32);
			if (game->map->map[y][x] == 'P')
			{
				game->map->p_x = x;
				game->map->p_y = y;
			}
			if (game->map->map[y][x] == 'C')
				print_with_alpha(&game->crate[game->frame % 4 + 4],
					&game->back, x * 32, y * 32);
			if (game->map->map[y][x] == 'E')
				if (game->col_count)
					print_with_alpha(&game->crate[0], &game->back,
						x * 32, y * 32);
		}
	}
	load_wall(game);
}

void	put_in_front(t_game *game, int x)
{
	if (game->won && !game->col_count)
		put_pxl_to_win(game, &game->tiles[1],
			game->map->p_x * 32, game->map->p_y * 32);
	put_pxl_to_win(game, &game->player[game->frame % 4],
		game->map->p_x * 32, game->map->p_y * 32);
	if (game->won)
		put_pxl_to_win(game, &game->holy[game->frame % 16],
			game->map->p_x * 32 - 8, game->map->p_y * 32 - 8);
	put_pxl_to_win(game, &game->crate[4], (32 + (32 * (x - 1))),
		game->map->y * 32 - 32);
	if (FLY)
		(angel_move(game), demon_move(game));
}

void	load_front(t_game *game, int y, int x)
{
	put_pxl_to_win(game, &game->tiles[0], game->map->p_x * 32,
		game->map->p_y * 32);
	while (++y < game->map->y)
	{
		x = -1;
		while (++x < game->map->x)
		{
			if (game->map->map[y][x] == 'G' || (game->map->last_case == 'G'
				&& game->map->map[y][x] == 'P'))
				put_pxl_to_win(game, &game->trap[game->frame % 14],
					x * 32, y * 32);
			if (game->map->map[y][x] == 'E')
			{
				if (game->col_count)
					mlx_put_image_to_window(game->mlx, game->win,
						game->crate[0].image, x * 32, y * 32);
				else
				{
					print_with_alpha(&game->portal[game->frame % 6],
						&game->back, x * 32, y * 32);
				}
			}
		}
	}
	put_in_front(game, x);
}
