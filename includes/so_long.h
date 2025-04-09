/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:32:44 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/09 17:03:42 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct	s_map
{
	char	**map;
	size_t	rows;
	size_t	columns;
	int		fd;
	int		steps;
} t_map;

typedef enum e_error
{
	E_EXTENSION,
	E_CHAR_ERROR,
	E_PLAYER_OR_EXIT,
	E_COLLECTIBLE,
	E_MAP_DIMENSION,
	E_WALL,
	E_EMPTY_MAP,
	
} t_error;

//checker
void	checker(char *argv, t_map *game);
int		check_extension(char *arg, t_map *game);
void	check_dimension(t_map *game);
void	check_wall_lenght(t_map *game);
void	check_wall_width(t_map *game);


//check_map
void 	check_char(t_map *game);
void	check_coll(t_map *game);
void	check_player_exit(t_map *game);

//matrix_maker_free
char 	**matrix_maker(char *argv, t_map *game);
void	final_map(char *argv, size_t rows, t_map *game);
void	free_maptrix(t_map *game);

//utils
void	open_file(char *argv, t_map *game);
void	print_map(t_map *game);
size_t	lenchar(char *str, char s);

//errors
void	errors(t_map *game, int err);

#endif