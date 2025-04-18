/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:01:04 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/17 18:02:37 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_gob(t_game *game, t_time current_time)
{
	double	now;
	double	old;

	now = current_time.tv_sec + current_time.tv_usec / 1e6;
	old = game->last_gob_sec.tv_sec + game->last_gob_sec.tv_usec / 1e6;
	if ((now - old) >= 1.0)
	{
		game->id.idx_gob = (game->id.idx_gob + 1) % 4;
		game->last_gob_sec = current_time;
	}
}

void	update_coll(t_game *game)
{
	game->img.idx_coll = (game->img.idx_coll + 1) % 2;
}

void	update_player(t_game *game)
{
	if (game->pg.pg_is_dead && game->pg.idx_death == 4)
	{
		game->in.winner_or_loser = 2;
		kill_em_all(game);
	}
	if (game->id.idx_exit == 4)
	{
		game->in.winner_or_loser = 1;
		kill_em_all(game);
	}
	if (!game->pg.pg_is_dead && !game->pg.pg_is_going_out)
		game->pg.idx_pg = (game->pg.idx_pg + 1) % 2;
	if (game->pg.pg_is_going_out && game->pg.no_more_coll)
		game->id.idx_exit = (game->id.idx_exit + 1) % 5;
	else if (game->pg.pg_is_dead && game->pg.idx_death != 4)
		game->pg.idx_death = (game->pg.idx_death + 1) % 5;
}

int	update(t_game *game)
{
	t_time	current_sec;
	double	now;
	double	old;

	gettimeofday(&current_sec, NULL);
	now = current_sec.tv_sec + current_sec.tv_usec / 1e6;
	old = game->last_sec.tv_sec + game->last_sec.tv_usec / 1e6;
	if ((game->pg.pg_start_x == game->in.exit_x
			&& game->pg.pg_start_y == game->in.exit_y)
		&& !game->pg.pg_is_dead)
		game->pg.pg_is_going_out = 1;
	else
		game->pg.pg_is_going_out = 0;
	if (game->in.coll_coll == game->in.tot_coll)
		game->pg.no_more_coll = 1;
	update_gob(game, current_sec);
	if (now - old >= 0.2)
	{
		update_coll(game);
		update_player(game);
		rendering(game);
		print_on_screen(game);
		game->last_sec = current_sec;
	}
	return (0);
}
