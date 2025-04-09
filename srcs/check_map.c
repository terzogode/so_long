/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:09:08 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/09 16:34:40 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char(t_map *game)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
				game->map[i][j] != 'E' && game->map[i][j] != 'P' &&
				game->map[i][j] != 'C' && game->map[i][j] != '\n')
				{
					ft_printf("Char error in the map at row %d, col %d", i, j);
					errors(game, E_CHAR_ERROR);
				}
			j++;
		}
		i++;
	}
}

void	check_coll(t_map *game)
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
	if (coll < 1)
		errors(game, E_COLLECTIBLE);
}

void	check_player_exit(t_map *game)
{
	int	rows;
	int	col;
	int	player;
	int	exit;

	col = 0;
	rows = 0;
	player = 0;
	exit = 0;
	while (game->map[rows] != NULL)
	{
		col = 0;
		while (game->map[rows][col] != '\0')
		{
			if (game->map[rows][col] == 'P')
				player += 1;
			if (game->map[rows][col] == 'E')
				exit += 1;
			col++;
		}
		rows++;
	}
	if (player != 1 || exit != 1)
		errors(game, E_PLAYER_OR_EXIT);
}
