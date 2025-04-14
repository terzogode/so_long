/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:49:28 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/14 23:08:01 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *game, size_t x, size_t y)
{
	if (x < 0 || x >= game->rows || y < 0 || y >= game->columns
		|| (game->coll_check[x][y] != '0' && game->coll_check[x][y] != 'C'
		&& game->coll_check[x][y] != 'P'))
		return ;
	game->coll_check[x][y] = '1';
	flood_fill(game, x - 1, y);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
}

int	check_reachability(t_map *game)
{
	size_t	i;
	size_t	j;
	size_t	start_x;
	size_t	start_y;

	start_x = game->pg_start_x;
	start_y = game->pg_start_y;
	flood_fill(game, start_x, start_y);
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

char	**coll_dup_map(t_map *game)
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
