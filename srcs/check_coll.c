/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:49:28 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/16 23:32:26 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, size_t x, size_t y, bool exit_coll)
{
	if (x < 0 || x >= game->rows || y < 0 || y >= game->columns
		|| (game->coll_check[x][y] != '0' && game->coll_check[x][y] != 'C'
		&& game->coll_check[x][y] != 'P' && game->coll_check[x][y] != 'E'
		&& exit_coll))
		return ;
	if (x < 0 || x >= game->rows || y < 0 || y >= game->columns
		|| (game->exit_check[x][y] != '0' && game->exit_check[x][y] != 'C'
		&& game->exit_check[x][y] != 'P' && game->exit_check[x][y] != 'E'
		&& !exit_coll))
		return ;
	if (exit_coll)
		game->coll_check[x][y] = '1';
	if (!exit_coll)
		game->exit_check[x][y] = '1';
	flood_fill(game, x - 1, y, exit_coll);
	flood_fill(game, x + 1, y, exit_coll);
	flood_fill(game, x, y - 1, exit_coll);
	flood_fill(game, x, y + 1, exit_coll);
}

int	check_coll_reachability(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	start_x;
	size_t	start_y;

	start_x = game->pg.pg_start_x;
	start_y = game->pg.pg_start_y;
	flood_fill(game, start_x, start_y, 1);
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->coll_check[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_exit_reachability(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	start_x;
	size_t	start_y;

	start_x = game->pg.pg_start_x;
	start_y = game->pg.pg_start_y;
	flood_fill(game, start_x, start_y, 0);
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->exit_check[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**coll_dup_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	game->coll_check = ft_calloc(game->rows, sizeof(char *));
	if (!game->coll_check)
		return (NULL);
	while (i < game->rows)
	{
		game->coll_check[i] = ft_calloc(game->columns, sizeof(char));
		if (!game->coll_check[i])
		{
			free_maptrix(game, game->coll_check);
			free_maptrix(game, game->map);
			return (NULL);
		}
		j = 0;
		while (j < game->columns)
		{
			game->coll_check[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	return (game->coll_check);
}

char	**exit_dup_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	game->exit_check = ft_calloc(game->rows, sizeof(char *));
	if (!game->exit_check)
		return (NULL);
	while (i < game->rows)
	{
		game->exit_check[i] = ft_calloc(game->columns, sizeof(char));
		if (!game->exit_check[i])
		{
			free_maptrix(game, game->exit_check);
			free_maptrix(game, game->map);
			return (NULL);
		}
		j = 0;
		while (j < game->columns)
		{
			game->exit_check[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	return (game->exit_check);
}
