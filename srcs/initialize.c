/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:23:14 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/15 19:01:46 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_img(t_map *game)
{
	init_img_back(game);
	init_img_exit(game);
	init_img_death(game);
	init_img_gob(game);
}

void	init_img_back(t_map *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "sprite/wall.xpm",
			&game->width, &game->height);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "sprite/floor.xpm",
			&game->width, &game->height);
	game->img.coll = mlx_xpm_file_to_image(game->mlx, "sprite/coll.xpm",
			&game->width, &game->height);
	game->pg[0] = mlx_xpm_file_to_image(game->mlx, "sprite/pg0.xpm",
			&game->width, &game->height);
	game->pg[1] = mlx_xpm_file_to_image(game->mlx, "sprite/pg1.xpm",
			&game->width, &game->height);
	if (!game->img.wall || !game->img.floor || !game->pg[0]
		|| !game->pg[1] || !game->img.coll)
		errors(game, E_IMAX);
}

void	init_img_exit(t_map *game)
{
	game->stat_exit = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit0.xpm", &game->width, &game->height);
	game->exit_win[0] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit1.xpm", &game->width, &game->height);
	game->exit_win[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit2.xpm", &game->width, &game->height);
	game->exit_win[2]= mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit3.xpm", &game->width, &game->height);
	game->exit_win[3] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit4.xpm", &game->width, &game->height);
	game->exit_win[4] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit5.xpm", &game->width, &game->height);
	if (!game->stat_exit || !game->exit_win[0] \
		|| !game->exit_win[1] || !game->exit_win[2] \
		|| !game->exit_win[3] || !game->exit_win[4])
		errors(game, E_IMAX);
}

void	init_img_death(t_map *game)
{
	game->death[0] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death0.xpm", &game->width, &game->height);
	game->death[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death1.xpm", &game->width, &game->height);
	game->death[2] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death2.xpm", &game->width, &game->height);
	game->death[3] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death3.xpm", &game->width, &game->height);
	game->death[4] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death4.xpm", &game->width, &game->height);
	if (!game->death[0] || !game->death[1] \
		|| !game->death[2] || !game->death[3] \
		|| !game->death[4])
		errors(game, E_IMAX);
}

void	init_img_gob(t_map *game)
{

	game->gob[0] = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob0.xpm", &game->width, &game->height);
	game->gob[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob1.xpm", &game->width, &game->height);
	game->gob[2] = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob2.xpm", &game->width, &game->height);
	game->gob[3] = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob3.xpm", &game->width, &game->height);
	if (!game->gob[0] || !game->gob[1] \
		|| !game->gob[2] || !game->gob[3])
		errors(game, E_IMAX);
}
