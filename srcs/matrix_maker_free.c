/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_maker_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:52:35 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/15 22:49:13 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maptrix(t_game *game, char **matrix)
{
	size_t	i;

	i = 0;
	while (i < game->rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	final_map(char *argv, size_t rows, t_game *game)
{
	size_t	i;
	char	*line;

	line = NULL;
	i = 0;
	game->map = ft_calloc(rows + 1, sizeof(char *));
	if (!game->map)
	{
		ft_printf ("I see no map up here");
		exit (1);
	}
	open_file(argv, game);
	while (i < rows)
	{
		line = get_next_line(game->fd);
		game->map[i] = line;
		if (ft_strchr(line, '\n'))
			game->map[i][ft_strlen(line) - 1] = '\0';
		i++;
	}
	game->map[i] = NULL;
	close(game->fd);
	if (game->map[0] == 0)
		errors (game, E_EMPTY_MAP);
}

char	**matrix_maker(char *argv, t_game *game)
{
	char	*line;
	size_t	col;
	size_t	rows;

	rows = 0;
	col = 0;
	line = NULL;
	open_file(argv, game);
	line = get_next_line(game->fd);
	while (line != NULL)
	{
		if (rows == 0)
			col = ft_strlen(line);
		rows++;
		free(line);
		line = get_next_line(game->fd);
	}
	close(game->fd);
	final_map(argv, rows, game);
	game->columns = col - 1;
	game->rows = rows;
	return (game->map);
}
