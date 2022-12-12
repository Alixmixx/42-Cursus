/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:08:48 by alixmix           #+#    #+#             */
/*   Updated: 2022/12/11 00:15:11 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_game *game)
{
	init_img(game, game->tiles, "./img/tiles_xpm/floor0.xpm", 10);
	init_img(game, game->wall, "./img/wall_xpm/wall1.xpm", 8);
	init_img(game, game->crate, "./img/crates_xpm/crate0.xpm", 8);
	init_img(game, game->player, "./img/bladekeeper/1.xpm", 4);
	init_img(game, game->trap, "./img/trap_xpm/a.xpm", 14);
	init_img(game, game->portal, "./img/portal_xpm/1.xpm", 6);
	init_img(game, game->num, "./img/font_xpm/0.xpm", 10);
	init_img(game, game->holy, "./img/holy_xpm/a.xpm", 16);
	game->back.image = mlx_new_image(game->mlx, game->map->x * 32,
			game->map->y * 32);
	game->back.data = mlx_get_data_addr(game->back.image, &game->back.bpp,
			&game->back.size_line, &game->back.format);
	game->front.image = mlx_new_image(game->mlx, game->map->x * 32,
			game->map->y * 32);
	game->front.data = mlx_get_data_addr(game->front.image, &game->front.bpp,
			&game->front.size_line, &game->front.format);
	(collectible_count(game), game->case_size = 32, game->power_up = 0,
		game->won = 0, game->moves = 0, game->loop = 0, game->frame = 0);
	game->lost = 0;
	game->loop_frame = LOOP;
	game->map->on_trap = 0;
	game->map->last_case = '0';
}

void	init_img(t_game *game, t_img *img, char *s, int size)
{
	int		i;
	int		digit;
	char	*path;

	i = 0;
	path = strdup(s);
	if (!path)
		(game_exit(game), exit(ERROR));
	digit = strlen(path) - 5;
	while (i < size)
	{
		img[i].image = mlx_xpm_file_to_image(game->mlx, path,
				&img[i].width, &img[i].height);
		if (!img[i].image)
			(free(path), game_exit(game), exit(ERROR));
		img[i].data = mlx_get_data_addr(img[i].image, &img[i].bpp,
				&img[i].size_line, &img[i].format);
		if (!img[i].data)
			(free(path), game_exit(game), exit(ERROR));
		path[digit] = path[digit] + 1;
		i++;
	}
	free(path);
}

void	put_pxl_to_win(t_game *game, t_img *player, int w, int h)
{
	int	x;
	int	y;
	int	color;
	int	step;

	y = 0;
	while (y < player->height)
	{
		x = 0;
		while (x < player->width)
		{
			step = y * (player->size_line) + x * player->bpp / 8;
			color = (player->data[step]) + (player->data[step + 1] << 8)
				+ (player->data[step + 2] << 16)
				+ (player->data[step + 3] << 24);
			x++;
			if ((color << 24) != 0)
				mlx_pixel_put(game->mlx, game->win, w + x, h + y, color);
		}
		y++;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && y >= 0)
	{
		pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
	}
}

void	print_with_alpha(t_img *img, t_img *dest, int x, int y)
{
	int	color;
	int	i;
	int	j;
	int	pos;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			pos = i * (img->size_line) + j * img->bpp / 8;
			color = (img->data[pos]) + (img->data[pos + 1] << 8)
				+ (img->data[pos + 2] << 16) + (img->data[pos + 3] << 24);
			j++;
			if (img->data[pos] != 0)
				img_pix_put(dest, x + j, y + i, color);
		}
		i++;
	}
}
