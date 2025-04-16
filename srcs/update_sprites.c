/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:01:04 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/17 01:08:19 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_gob(t_game *game)
{
	game->idx_gob = (game->idx_gob + 1) % 4;
}

void	update_coll(t_game *game)
{
	game->img.idx_coll = (game->img.idx_coll + 1) % 2;
}

void	update_player(t_game *game)
{
	if (game->pg.pg_is_dead && game->pg.idx_death == 4)
	{
		ft_printf("You died in %d moves\n", game->pg.pg_moves);
		kill_em_all(game);
	}
	if (game->idx_exit == 4)
	{
		ft_printf("You won in %d moves\n", game->pg.pg_moves);
		kill_em_all(game);
	}
	if (!game->pg.pg_is_dead && !game->pg.pg_is_going_out)
		game->pg.idx_pg = (game->pg.idx_pg + 1) % 2;
	if (game->pg.pg_is_going_out && game->pg.no_more_coll)
		game->idx_exit = (game->idx_exit + 1) % 5;
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
	print_on_screen(game);
	if ((game->pg.pg_start_x == game->exit_x
			&& game->pg.pg_start_y == game->exit_y)
		&& !game->pg.pg_is_dead)
		game->pg.pg_is_going_out = 1;
	else
		game->pg.pg_is_going_out = 0;
	if (game->coll_coll == game->tot_coll)
		game->pg.no_more_coll = 1;
	if (now - old >= 0.3)
	{
		update_gob(game);
		update_coll(game);
		update_player(game);
		rendering(game);
		game->last_sec = current_sec;
	}
	return (0);
}
