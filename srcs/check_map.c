/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:09:08 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/18 17:34:03 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
				game->map[i][j] != 'E' && game->map[i][j] != 'P' &&
				game->map[i][j] != 'C' && game->map[i][j] != 'G')
			{
				ft_printf("Error: Char error at row %d, col %d\n", i, j);
				errors1(game, E_CHAR_ERROR);
			}
			j++;
		}
		i++;
	}
}

void	check_coll(t_game *game)
{
	int	rows;
	int	columns;
	int	coll;

	coll = 0;
	columns = 0;
	rows = 0;
	while (game->map[rows] != NULL)
	{
		columns = 0;
		while (game->map[rows][columns] != '\0')
		{
			if (game->map[rows][columns] == 'C')
				coll += 1;
			columns++;
		}
		rows++;
	}
	game->in.tot_coll = coll;
	if (coll < 1)
		errors1(game, E_COLLECTIBLE);
}

void	check_player(t_game *game)
{
	int	rows;
	int	col;
	int	player;

	col = 0;
	rows = 0;
	player = 0;
	while (game->map[rows] != NULL)
	{
		col = 0;
		while (game->map[rows][col] != '\0')
		{
			if (game->map[rows][col] == 'P')
			{
				player += 1;
				game->pg.pg_start_y = rows;
				game->pg.pg_start_x = col;
			}
			col++;
		}
		rows++;
	}
	if (player != 1)
		errors1(game, E_PLAYER);
}

void	check_exit(t_game *game)
{
	int	rows;
	int	col;
	int	exit;

	col = 0;
	rows = 0;
	exit = 0;
	while (game->map[rows] != NULL)
	{
		col = 0;
		while (game->map[rows][col] != '\0')
		{
			if (game->map[rows][col] == 'E')
			{
				exit += 1;
				game->in.exit_y = rows;
				game->in.exit_x = col;
			}
			col++;
		}
		rows++;
	}
	if (exit != 1)
		errors1(game, E_EXIT);
}
