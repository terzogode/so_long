/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:09:09 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/16 17:22:41 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void kill_em_all(t_game *game)
{
	cleaning(game);
	mlx_destroy_display(game->mlx);
	free_maptrix(game, game->map);
	
}
void cleaning(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.coll);
	mlx_destroy_image(game->mlx, game->pg.pg[0]);
	mlx_destroy_image(game->mlx, game->pg.pg[1]);
	mlx_destroy_image(game->mlx, game->stat_exit[0]);
	mlx_destroy_image(game->mlx, game->stat_exit[1]);
	mlx_destroy_image(game->mlx, game->stat_exit[2]);
	mlx_destroy_image(game->mlx, game->exit_win[0]);
	mlx_destroy_image(game->mlx, game->exit_win[1]);
	mlx_destroy_image(game->mlx, game->exit_win[2]);
	mlx_destroy_image(game->mlx, game->exit_win[3]);
	mlx_destroy_image(game->mlx, game->exit_win[4]);
	mlx_destroy_image(game->mlx, game->pg.death[0]);
	mlx_destroy_image(game->mlx, game->pg.death[1]);
	mlx_destroy_image(game->mlx, game->pg.death[2]);
	mlx_destroy_image(game->mlx, game->pg.death[3]);
	mlx_destroy_image(game->mlx, game->pg.death[4]);
	mlx_destroy_image(game->mlx, game->gob[0]);
	mlx_destroy_image(game->mlx, game->gob[1]);
	mlx_destroy_image(game->mlx, game->gob[2]);
	mlx_destroy_image(game->mlx, game->gob[3]);
}