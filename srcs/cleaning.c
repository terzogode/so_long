/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:09:09 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/17 15:59:32 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	kill_em_all(t_game *game)
{
	if (game->in.winner_or_loser == 1)
		ft_printf("You won in %d moves\n", game->pg.pg_moves);
	if (game->in.winner_or_loser == 2)
		ft_printf("You died in %d moves\n", game->pg.pg_moves);
	if (game->in.winner_or_loser == 0)
		ft_printf("I spent lot of time on this game! Play it, please!\n");
	cleaning(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_maptrix(game, game->map);
	free(game->mlx);
	exit (0);
	return (0);
}

void	cleaning(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.coll[0]);
	mlx_destroy_image(game->mlx, game->img.coll[1]);
	mlx_destroy_image(game->mlx, game->pg.pg[0]);
	mlx_destroy_image(game->mlx, game->pg.pg[1]);
	mlx_destroy_image(game->mlx, game->id.stat_exit[0]);
	mlx_destroy_image(game->mlx, game->id.stat_exit[1]);
	mlx_destroy_image(game->mlx, game->id.stat_exit[2]);
	mlx_destroy_image(game->mlx, game->id.exit_win[0]);
	mlx_destroy_image(game->mlx, game->id.exit_win[1]);
	mlx_destroy_image(game->mlx, game->id.exit_win[2]);
	mlx_destroy_image(game->mlx, game->id.exit_win[3]);
	mlx_destroy_image(game->mlx, game->id.exit_win[4]);
	mlx_destroy_image(game->mlx, game->pg.death[0]);
	mlx_destroy_image(game->mlx, game->pg.death[1]);
	mlx_destroy_image(game->mlx, game->pg.death[2]);
	mlx_destroy_image(game->mlx, game->pg.death[3]);
	mlx_destroy_image(game->mlx, game->pg.death[4]);
	mlx_destroy_image(game->mlx, game->id.gob[0]);
	mlx_destroy_image(game->mlx, game->id.gob[1]);
	mlx_destroy_image(game->mlx, game->id.gob[2]);
	mlx_destroy_image(game->mlx, game->id.gob[3]);
}
