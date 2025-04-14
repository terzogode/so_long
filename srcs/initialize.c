/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:23:14 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/14 22:50:20 by mbrighi          ###   ########.fr       */
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
	game->img.pg0 = mlx_xpm_file_to_image(game->mlx, "sprite/pg0.xpm",
			&game->width, &game->height);
	game->img.pg1 = mlx_xpm_file_to_image(game->mlx, "sprite/pg1.xpm",
			&game->width, &game->height);
	if (!game->img.wall || !game->img.floor || !game->img.pg0
		|| !game->img.pg1 || !game->img.coll)
		errors(game, E_IMAX);
}

void	init_img_exit(t_map *game)
{
	game->exit.exit0 = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit0.xpm", &game->width, &game->height);
	game->exit.exit1 = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit1.xpm", &game->width, &game->height);
	game->exit.exit2 = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit2.xpm", &game->width, &game->height);
	game->exit.exit3 = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit3.xpm", &game->width, &game->height);
	game->exit.exit4 = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit4.xpm", &game->width, &game->height);
	game->exit.exit5 = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit/exit5.xpm", &game->width, &game->height);
	if (!game->exit.exit0 || !game->exit.exit1 \
		|| !game->exit.exit2 || !game->exit.exit3 \
		|| !game->exit.exit3 || !game->exit.exit5)
		errors(game, E_IMAX);
}

void	init_img_death(t_map *game)
{
	game->death.death0 = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death0.xpm", &game->width, &game->height);
	game->death.death1 = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death1.xpm", &game->width, &game->height);
	game->death.death2 = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death2.xpm", &game->width, &game->height);
	game->death.death3 = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death3.xpm", &game->width, &game->height);
	game->death.death4 = mlx_xpm_file_to_image(game->mlx,
			"sprite/death/death4.xpm", &game->width, &game->height);
	if (!game->death.death0 || !game->death.death1 \
		|| !game->death.death2 || !game->death.death3 \
		|| !game->death.death4)
		errors(game, E_IMAX);
}

void	init_img_gob(t_map *game)
{
	game->gob.gob0 = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob0.xpm", &game->width, &game->height);
	game->gob.gob1 = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob1.xpm", &game->width, &game->height);
	game->gob.gob2 = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob2.xpm", &game->width, &game->height);
	game->gob.gob3 = mlx_xpm_file_to_image(game->mlx,
			"sprite/gob/gob3.xpm", &game->width, &game->height);
	if (!game->gob.gob0 || !game->gob.gob1 \
		|| !game->gob.gob2 || !game->gob.gob3)
		errors(game, E_IMAX);
}
