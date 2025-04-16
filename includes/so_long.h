/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:32:44 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/17 01:05:29 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIX 64

# include <time.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*coll[2];
	int		idx_coll;
}	t_img;

typedef struct s_pg
{
	void	*pg[2];
	int		pg_start_x;
	int		pg_start_y;
	int		idx_pg;
	bool	pg_is_dead;
	bool	no_more_coll;
	bool	pg_is_going_out;
	void	*death[5];
	int		idx_death;
	int		pg_moves;
	int		pg_temp_move;
}	t_pg;

typedef struct timeval	t_time;

typedef struct s_map
{
	char	**map;
	char	**coll_check;
	char	**exit_check;
	size_t	rows;
	size_t	columns;
	int		fd;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		tot_coll;
	int		coll_coll;
	int		exit_y;
	int		exit_x;
	t_img	img;
	void	*exit_win[5];
	int		idx_exit;
	void	*gob[4];
	t_time	last_sec;
	void	*stat_exit[3];
	int		idx_gob;
	t_pg	pg;
}	t_game;

typedef enum e_error
{
	E_EXTENSION,
	E_CHAR_ERROR,
	E_PLAYER,
	E_EXIT,
	E_COLLECTIBLE,
	E_MAP_DIMENSION,
	E_WALL,
	E_EMPTY_MAP,
	E_IMAX,
	E_UNREACHABLE_COLL,
}	t_error;

//checker
void	checker(char *argv, t_game *game);
int		check_extension(char *arg, t_game *game);
void	check_dimension(t_game *game);
void	check_wall_lenght(t_game *game);
void	check_wall_width(t_game *game);

//check_map
void	check_char(t_game *game);
void	check_coll(t_game *game);
void	check_player(t_game *game);
void	check_exit(t_game *game);

//check_coll
void	flood_fill(t_game *game, size_t x, size_t y, bool exit_coll);
int		check_coll_reachability(t_game *game);
int		check_exit_reachability(t_game *game);
char	**coll_dup_map(t_game *game);
char	**exit_dup_map(t_game *game);

//matrix_maker_free
void	final_map(char *argv, size_t rows, t_game *game);
void	free_maptrix(t_game *game, char **matrix);
char	**matrix_maker(char *argv, t_game *game);

//utils
void	open_file(char *argv, t_game *game);
void	print_map(t_game *game);
void	print_on_screen(t_game *game);

//errors
void	errors(t_game *game, int err);
void	errors1(t_game *game, int err);

//letsgoski
void	rendering(t_game *game);
void	letsfill(t_game *game, int x, int y);
void	letsgoski(t_game *game);
void	player_do_things(t_game *game);
void	player_is_gone(t_game *game);

//initialize
void	initialize_img(t_game *game);
void	init_img_back(t_game *game);
void	init_img_exit(t_game *game);
void	init_img_death(t_game *game);
void	init_img_gob(t_game *game);

//update_sprite
void	update_gob(t_game *game);
int		update(t_game *game);

//keypress
int		handle_key(int keycode, void *param);
int		can_move_to(t_game *game, int x, int y);
void	move_player(t_game *game, int dx, int dy, int move);

//cleaning
void	kill_em_all(t_game *game);
void	cleaning(t_game *game);

#endif