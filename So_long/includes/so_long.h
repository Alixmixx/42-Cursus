/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:26:22 by alixmix           #+#    #+#             */
/*   Updated: 2022/12/10 23:34:31 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <errno.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include <math.h>
# include <time.h>

# ifndef FLY
#  define FLY 1
# endif

# define LOOP 50000
# define ERROR 1
# define SUCCESS 0
# define ERR_ARG "Invalid number of arguments"
# define ERR_ENV "Environnement error"
# define ERR_MAP "Map error"

extern char	**environ;

typedef struct s_checker
{
	int	newline;
	int	border;
	int	ply;
	int	item;
	int	exit;
	int	x;
	int	y;
}				t_checker;

typedef struct s_map
{
	char	**map;
	int		p_lastx;
	int		p_lasty;
	int		last_case;
	int		p_x;
	int		p_y;
	int		on_trap;
	int		x;
	int		y;
	int		angel_x;
	int		angel_y;
	int		demon_x;
	int		demon_y;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	tiles[10];
	t_img	wall[10];
	t_img	num[10];
	t_img	trap[14];
	t_img	crate[8];
	t_img	portal[8];
	t_img	holy[16];
	t_img	exit[2];
	t_img	player[4];
	t_img	aura[10];
	t_img	back;
	t_img	front;
	int		power_up;
	int		loop_frame;
	int		lost;
	int		won;
	int		loop;
	int		moves;
	int		frame;
	int		init;
	int		col_count;
	int		case_size;
}				t_game;

//		RENDER
int		load_obstacle(t_game *game, int x, int y);
void	put_in_front(t_game *game, int x);
void	load_wall(t_game *game);
void	load_back(t_game *game, int y, int x);
void	load_front(t_game *game, int y, int x);

//		IMAGE
void	load_img(t_game *game);
void	init_img(t_game *game, t_img *img, char *s, int size);
void	put_pxl_to_win(t_game *game, t_img *player, int w, int h);
void	img_pix_put(t_img *img, int x, int y, int color);
void	print_with_alpha(t_img *img, t_img *dest, int x, int y);

//		READ_MAP
void	free_map(t_map *map);
void	map_init(t_game *game, char *filename, int i);

//		MAP
void	free_img(t_game *game, t_img *img, int size);
int		game_exit(t_game *game);
int		game_won(t_game *game);
void	collectible_count(t_game *game);
void	put_nbr_window(t_game *game, int nb, int x);

//		INPUT
int		handle_no_event(t_game *game);
int		handle_input(int keysim, t_game *game);
void	handle_frame(t_game *game, int x, int y);
void	more_input(int keysim, t_game *game);
void	update_map(t_game *game);

//		ERROR
int		putstr_error(char *error);
void	msg_error(char *error, int ret);
void	put_error(char *error, char *file, int ret);

//		MAP_CHECKER
int		map_checker(char *filename);

//		MAZE
int		maze_solver(t_map *map, char goal, int x, int y);

//		FLY
void	angel_move(t_game *game);
void	demon_move(t_game *game);
void	fly_init(t_game *game);

#endif
