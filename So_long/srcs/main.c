/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:27:09 by alixmix           #+#    #+#             */
/*   Updated: 2022/12/11 14:38:44 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	main_loop(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->back.image, 0, 0);
	mlx_hook(game->win, 17, ButtonPressMask, &game_exit, game);
	mlx_loop_hook(game->mlx, &handle_no_event, game);
	mlx_key_hook(game->win, &handle_input, game);
	if (game->lost)
		game_won(game);
	if (game)
		mlx_loop(game->mlx);
	free_map(game->map);
	free(game);
}

void	main_init(t_game *game)
{
	if (!maze_solver(game->map, 'E', game->map->p_x, game->map->p_y))
		(free_map(game->map), free(game),
			put_error(ERR_MAP, NULL, ERROR), exit(ERROR));
	game->mlx = mlx_init();
	if (!game->mlx)
		(free_map(game->map), free(game),
			put_error(ERR_MAP, NULL, ERROR), exit(ERROR));
	game->win = mlx_new_window(game->mlx, game->map->x * 32,
			game->map->y * 32, "So Long");
	if (!game->win)
		(mlx_destroy_display(game->mlx), free(game->mlx), free_map(game->map),
			free(game), put_error(ERR_MAP, NULL, ERROR), exit(ERROR));
	(fly_init(game), load_img(game), load_back(game, -1, -1),
		load_front(game, -1, -1));
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		y;

	if (!*environ)
		put_error(ERR_ENV, NULL, ERROR);
	if (ac != 2)
		put_error(ERR_ARG, NULL, ERROR);
	y = map_checker(av[1]);
	game = malloc(sizeof(*game));
	if (!game)
		(put_error(strerror(ENOMEM), NULL, ERROR), exit(ERROR));
	game->map = malloc(sizeof(*game->map));
	if (!game->map)
		(free(game), put_error(strerror(ENOMEM), NULL, ERROR), exit(ERROR));
	game->map->map = malloc(sizeof(*game->map->map) * (y + 1));
	if (!game->map->map)
		(free(game->map), free(game), put_error(strerror(ENOMEM), NULL, ERROR),
			exit(ERROR));
	game->map->y = y;
	map_init(game, av[1], -1);
	main_init(game);
	main_loop(game);
	return (0);
}
