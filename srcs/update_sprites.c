/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:01:04 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/15 23:09:10 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_gob(t_game *game)
{
	game->idx_gob = (game->idx_gob + 1) % 4;
}

void	update_player(t_game *game)
{
	if (game->pg.pg_stat[0] == 0)
		game->pg.idx_pg = (game->pg.idx_pg + 1) % 2;
	else if (game->pg.pg_stat[0] == 1)
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
	//printf("diff now- old: %f\n", now - old);
	if (now - old >= 1.0)
	{
		update_gob(game);
		update_player(game);
		rendering(game);
		game->last_sec = current_sec;
	}
	return (0);
}

