/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:24:51 by alixmix           #+#    #+#             */
/*   Updated: 2022/12/10 23:54:06 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_game *game, t_img *img, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (img[i].image)
			mlx_destroy_image(game->mlx, img[i].image);
		i++;
	}
}

int	game_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_img(game, game->tiles, 10);
	free_img(game, game->wall, 8);
	free_img(game, game->crate, 8);
	free_img(game, game->player, 4);
	free_img(game, game->trap, 14);
	free_img(game, game->portal, 6);
	free_img(game, game->holy, 16);
	free_img(game, game->num, 10);
	free_img(game, &game->back, 1);
	free_img(game, &game->front, 1);
	free_map(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	game = NULL;
	exit (0);
}

int	game_won(t_game *game)
{
	if (!game->won)
		game->frame = 0;
	game->won++;
	if (game->power_up)
		game->power_up = 0;
	if (game->won > LOOP)
	{
		game_exit(game);
		exit(0);
	}
	return (0);
}

void	collectible_count(t_game *game)
{
	int	x;
	int	y;

	game->col_count = 0;
	y = 0;
	while (y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			if (game->map->map[y][x] == 'C')
				game->col_count++;
			x++;
		}
		y++;
	}
}

void	put_nbr_window(t_game *game, int nb, int x)
{
	if (nb > 9)
		put_nbr_window(game, nb / 10, x - 32);
	print_with_alpha(&game->num[nb % 10], &game->front, x,
		game->map->y * 32 - 32);
	print_with_alpha(&game->num[nb % 10], &game->back, x,
		game->map->y * 32 - 32);
}
