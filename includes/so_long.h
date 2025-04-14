/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:32:44 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/14 23:47:43 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIX 32

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_gob
{
	void	*gob0;
	void	*gob1;
	void	*gob2;
	void	*gob3;
}	t_gob;

typedef struct s_death
{
	void	*death0;
	void	*death1;
	void	*death2;
	void	*death3;
	void	*death4;
}	t_death;

typedef struct s_exit
{
	void	*exit0;
	void	*exit1;
	void	*exit2;
	void	*exit3;
	void	*exit4;
	void	*exit5;
}	t_exit;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*pg0;
	void	*pg1;
	void	*enemies;
	void	*coll;
}	t_img;

typedef struct s_map
{
	char	**map;
	char	**coll_check;
	size_t	rows;
	size_t	columns;
	int		fd;
	int		steps;
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	int		num_coll;
	int		pg_start_y;
	int		pg_start_x;
	int		exit_y;
	int		exit_x;
	t_img	img;
	t_exit	exit;
	t_death	death;
	t_gob	gob;
}	t_map;

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
	E_
}	t_error;

//checker
void	checker(char *argv, t_map *game);
int		check_extension(char *arg, t_map *game);
void	check_dimension(t_map *game);
void	check_wall_lenght(t_map *game);
void	check_wall_width(t_map *game);

//check_map
void	check_char(t_map *game);
void	check_coll(t_map *game);
void	check_player(t_map *game);
void	check_exit(t_map *game);

//check_coll
void	flood_fill(t_map *game, size_t x, size_t y);
int		check_reachability(t_map *game);
char	**coll_dup_map(t_map *game);

//matrix_maker_free
void	final_map(char *argv, size_t rows, t_map *game);
void 	free_maptrix(t_map *game, char **matrix);
char	**matrix_maker(char *argv, t_map *game);

//utils
void	open_file(char *argv, t_map *game);
void	print_map(t_map *game);

//errors
void	errors(t_map *game, int err);

//letsgoski
void	init_map(t_map *game);
void	letsfill(t_map *game, int x, int y);
void	letsgoski(t_map *game);

//initialize
void	initialize_img(t_map *game);
void	init_img_back(t_map *game);
void	init_img_exit(t_map *game);
void	init_img_death(t_map *game);
void	init_img_gob(t_map *game);

#endif