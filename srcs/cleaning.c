/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:09:09 by mbrighi           #+#    #+#             */
/*   Updated: 2025/05/05 14:36:30 by mbrighi          ###   ########.fr       */
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
	cleaning1(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_maptrix(game, game->map);
	free(game->mlx);
	exit (0);
	return (0);
}

void	cleaning(t_game *game)
{
	if (game->img.wall != NULL)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.floor != NULL)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->pg.pg[0] != NULL)
		mlx_destroy_image(game->mlx, game->pg.pg[0]);
	if (game->pg.pg[1] != NULL)
		mlx_destroy_image(game->mlx, game->pg.pg[1]);
	if (game->id.stat_exit[0] != NULL)
		mlx_destroy_image(game->mlx, game->id.stat_exit[0]);
	if (game->id.stat_exit[1] != NULL)
		mlx_destroy_image(game->mlx, game->id.stat_exit[1]);
	if (game->id.stat_exit[2] != NULL)
		mlx_destroy_image(game->mlx, game->id.stat_exit[2]);
	if (game->id.exit_win[0] != NULL)
		mlx_destroy_image(game->mlx, game->id.exit_win[0]);
	if (game->id.exit_win[1] != NULL)
		mlx_destroy_image(game->mlx, game->id.exit_win[1]);
	if (game->id.exit_win[2] != NULL)
		mlx_destroy_image(game->mlx, game->id.exit_win[2]);
	if (game->id.exit_win[3] != NULL)
		mlx_destroy_image(game->mlx, game->id.exit_win[3]);
	if (game->id.exit_win[4] != NULL)
		mlx_destroy_image(game->mlx, game->id.exit_win[4]);
}

void	cleaning1(t_game *game)
{
	if (game->img.coll[0] != NULL)
		mlx_destroy_image(game->mlx, game->img.coll[0]);
	if (game->img.coll[1] != NULL)
		mlx_destroy_image(game->mlx, game->img.coll[1]);
	if (game->pg.death[0] != NULL)
		mlx_destroy_image(game->mlx, game->pg.death[0]);
	if (game->pg.death[1] != NULL)
		mlx_destroy_image(game->mlx, game->pg.death[1]);
	if (game->pg.death[2] != NULL)
		mlx_destroy_image(game->mlx, game->pg.death[2]);
	if (game->pg.death[3] != NULL)
		mlx_destroy_image(game->mlx, game->pg.death[3]);
	if (game->pg.death[4] != NULL)
		mlx_destroy_image(game->mlx, game->pg.death[4]);
	if (game->id.gob[0] != NULL)
		mlx_destroy_image(game->mlx, game->id.gob[0]);
	if (game->id.gob[1] != NULL)
		mlx_destroy_image(game->mlx, game->id.gob[1]);
	if (game->id.gob[2] != NULL)
		mlx_destroy_image(game->mlx, game->id.gob[2]);
	if (game->id.gob[3] != NULL)
		mlx_destroy_image(game->mlx, game->id.gob[3]);
}
