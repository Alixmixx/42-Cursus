/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:16:49 by alixmix           #+#    #+#             */
/*   Updated: 2022/12/12 12:04:56 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_frame(t_game *game, int x, int y)
{
	if (game->map->map[game->map->p_y][game->map->p_x] == 'G'
		|| game->map->on_trap)
	{
		if (game->frame % 14 > 6 && game->frame % 14 < 9)
			(put_pxl_to_win(game, &game->player[3],
					game->map->p_x, game->map->p_y), game->lost = 1);
	}
	game->loop = 0;
	game->frame++;
	load_back(game, -1, -1);
	mlx_put_image_to_window(game->mlx, game->win, game->back.image, 0, 0);
	put_nbr_window(game, game->moves, game->map->x * 32 - 32);
	x = 0;
	y = game->col_count;
	while (y > 0)
	{
		y /= 10;
		x++;
	}
	put_nbr_window(game, game->col_count, (32 * (x - 1)));
	if (game->col_count)
		mlx_put_image_to_window(game->mlx, game->win, game->crate[3].image,
			(32 + (32 * (x - 1))), game->map->y * 32 - 32);
	load_front(game, -1, -1);
}

int	handle_no_event(t_game *game)
{
	game->loop++;
	if (game->loop > game->loop_frame / 10)
		handle_frame(game, 0, 0);
	if (game->won)
		game_won(game);
	if (game->lost && game->frame % 14 == 0)
	{
		game_won(game);
		return (1);
	}
	return (0);
}

void	update_map(t_game *game)
{
	if (game->map->p_x != game->map->p_lastx
		|| game->map->p_y != game->map->p_lasty)
	{
		game->map->map[game->map->p_lasty][game->map->p_lastx]
			= game->map->last_case;
		if (game->map->map[game->map->p_y][game->map->p_x]
			== 'E' && !game->col_count)
		{
			game->won = 1;
			game->frame = 0;
		}
		if (game->map->map[game->map->p_y][game->map->p_x]
			== 'G' && ++game->map->on_trap)
			game->map->last_case = 'G';
		else
		{
			game->map->on_trap = 0;
			game->map->last_case = '0';
		}
		if (game->map->map[game->map->p_y][game->map->p_x] == 'C')
			game->col_count--;
		game->map->map[game->map->p_y][game->map->p_x] = 'P';
	}
}

void	more_input(int keysim, t_game *game)
{
	if (keysim == XK_Escape)
		game_exit(game);
	if (keysim == XK_space)
	{
		if (!game->power_up)
		{
			game->power_up = 1;
			game->loop_frame = LOOP / 2;
		}
		else
		{
			game->power_up = 0;
			game->loop_frame = LOOP;
		}
	}
	update_map(game);
	load_back(game, -1, -1);
}

int	handle_input(int keysim, t_game *game)
{
	if (game->lost || game->won)
		return (0);
	game->map->p_lastx = game->map->p_x;
	game->map->p_lasty = game->map->p_y;
	if (keysim == XK_Left || keysim == XK_a)
		if (game->map->map[game->map->p_y][game->map->p_x - 1] != '1')
			if (!(game->map->map[game->map->p_y][game->map->p_x - 1]
				== 'E' && game->col_count))
				(ft_printf("%d\n", ++game->moves), game->map->p_x -= 1);
	if (keysim == XK_Up || keysim == XK_w)
		if (game->map->map[game->map->p_y - 1][game->map->p_x] != '1')
			if (!(game->map->map[game->map->p_y - 1][game->map->p_x]
				== 'E' && game->col_count))
				(ft_printf("%d\n", ++game->moves), game->map->p_y -= 1);
	if (keysim == XK_Right || keysim == XK_d)
		if (game->map->map[game->map->p_y][game->map->p_x + 1] != '1')
			if (!(game->map->map[game->map->p_y][game->map->p_x + 1]
				== 'E' && game->col_count))
				(ft_printf("%d\n", ++game->moves), game->map->p_x += 1);
	if (keysim == XK_Down || keysim == XK_s)
		if (game->map->map[game->map->p_y + 1][game->map->p_x] != '1')
			if (!(game->map->map[game->map->p_y + 1][game->map->p_x]
				== 'E' && game->col_count))
				(ft_printf("%d\n", ++game->moves), game->map->p_y += 1);
	return (more_input(keysim, game), 0);
}
