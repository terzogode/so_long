/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:23:14 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/17 15:58:55 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_img(t_game *game)
{
	init_img_back(game);
	init_img_exit(game);
	init_img_death(game);
	init_img_gob(game);
}

void	init_img_back(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "sprite/wall.xpm",
			&game->width, &game->height);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "sprite/floor.xpm",
			&game->width, &game->height);
	game->img.coll[0] = mlx_xpm_file_to_image(game->mlx, "sprite/coll.xpm",
			&game->width, &game->height);
	game->img.coll[1] = mlx_xpm_file_to_image(game->mlx, "sprite/coll1.xpm",
			&game->width, &game->height);
	game->pg.pg[0] = mlx_xpm_file_to_image(game->mlx, "sprite/pg0.xpm",
			&game->width, &game->height);
	game->pg.pg[1] = mlx_xpm_file_to_image(game->mlx, "sprite/pg1.xpm",
			&game->width, &game->height);
	if (!game->img.wall || !game->img.floor || !game->pg.pg[0]
		|| !game->pg.pg[1] || !game->img.coll[0] || !game->img.coll[1])
		errors(game, E_IMAX);
}

void	init_img_exit(t_game *game)
{
	game->id.stat_exit[0] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit_0.xpm", &game->width, &game->height);
	game->id.stat_exit[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit_01.xpm", &game->width, &game->height);
	game->id.stat_exit[2] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit_1.xpm", &game->width, &game->height);
	game->id.exit_win[0] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/win_0.xpm", &game->width, &game->height);
	game->id.exit_win[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/win_1.xpm", &game->width, &game->height);
	game->id.exit_win[2] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/win_2.xpm", &game->width, &game->height);
	game->id.exit_win[3] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/win_3.xpm", &game->width, &game->height);
	game->id.exit_win[4] = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/win_4.xpm", &game->width, &game->height);
	if (!game->id.stat_exit[0] || !game->id.stat_exit[1] \
		|| !game->id.stat_exit[2] || !game->id.exit_win[0] \
		|| !game->id.exit_win[1] || !game->id.exit_win[2] \
		|| !game->id.exit_win[3] || !game->id.exit_win[4])
		errors(game, E_IMAX);
}

void	init_img_death(t_game *game)
{
	game->pg.death[0] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death0.xpm", &game->width, &game->height);
	game->pg.death[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death1.xpm", &game->width, &game->height);
	game->pg.death[2] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death2.xpm", &game->width, &game->height);
	game->pg.death[3] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death3.xpm", &game->width, &game->height);
	game->pg.death[4] = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death4.xpm", &game->width, &game->height);
	if (!game->pg.death[0] || !game->pg.death[1] \
		|| !game->pg.death[2] || !game->pg.death[3] \
		|| !game->pg.death[4])
		errors(game, E_IMAX);
}

void	init_img_gob(t_game *game)
{
	game->id.gob[0] = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob0.xpm", &game->width, &game->height);
	game->id.gob[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob1.xpm", &game->width, &game->height);
	game->id.gob[2] = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob2.xpm", &game->width, &game->height);
	game->id.gob[3] = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob3.xpm", &game->width, &game->height);
	if (!game->id.gob[0] || !game->id.gob[1] \
		|| !game->id.gob[2] || !game->id.gob[3])
		errors(game, E_IMAX);
}
