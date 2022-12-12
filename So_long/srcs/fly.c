/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fly.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:23:49 by amuller           #+#    #+#             */
/*   Updated: 2022/12/12 11:56:30 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	demon_move(t_game *game)
{
	int	x;
	int	y;

	if (game->map->p_x * 32 + 10 < game->map->demon_x)
		game->map->demon_x -= game->frame % 2 + 1;
	else if (game->map->p_x * 32 + 10 > game->map->demon_x)
		game->map->demon_x += game->frame % 2 + 1;
	if (game->map->p_y * 32 - 15 < game->map->demon_y)
		game->map->demon_y -= game->frame % 2 + 1;
	else if (game->map->p_y * 32 - 15 > game->map->demon_y)
		game->map->demon_y += game->frame % 2 + 1;
	put_pxl_to_win(game, &game->tiles[game->frame % 4 + 6],
		game->map->demon_x, game->map->demon_y);
	x = game->map->p_x * 32 - game->map->demon_x;
	y = game->map->p_y * 32 - game->map->demon_y;
	if (abs(x) + abs(y) < 64)
		mlx_string_put(game->mlx, game->win, game->map->demon_x + 10,
			game->map->demon_y, 0xb90510, "#*$@!");
}

void	angel_move(t_game *game)
{
	int	x;
	int	y;

	if (game->map->p_x * 32 - 10 < game->map->angel_x)
		game->map->angel_x--;
	else if (game->map->p_x * 32 - 10 > game->map->angel_x)
		game->map->angel_x++;
	if (game->map->p_y * 32 - 15 < game->map->angel_y)
		game->map->angel_y--;
	else if (game->map->p_y * 32 - 15 > game->map->angel_y)
		game->map->angel_y++;
	put_pxl_to_win(game, &game->tiles[game->frame % 4 + 2],
		game->map->angel_x, game->map->angel_y);
	x = game->map->p_x * 32 - game->map->angel_x;
	y = game->map->p_y * 32 - game->map->angel_y;
	if (abs(x) + abs(y) < 64)
		mlx_string_put(game->mlx, game->win, game->map->angel_x - 10,
			game->map->angel_y, 0x4cbf1b, "Bibop");
}

void	fly_init(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			if (game->map->map[y][x] == 'P')
			{
				game->map->angel_y = y * 32 - 10;
				game->map->angel_x = x * 32 - 15 ;
			}
			if (game->map->map[y][x] == 'E')
			{
				game->map->demon_y = y * 32;
				game->map->demon_x = x * 32;
			}
			x++;
		}
	y++;
	}
}
