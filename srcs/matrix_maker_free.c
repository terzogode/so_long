/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_maker_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:52:35 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/08 19:38:26 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maptrix(t_map *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	final_map(char *argv, size_t rows, t_map *game)
{
	size_t	i;
	char	*line;
	int		fd;

	line = NULL;
	i = 0;
	game->map = ft_calloc(rows + 1, sizeof(char *));
	if (!game->map)
	{
		ft_printf("I see no map up here");
		exit (1);
	}
	fd = open_file(argv);
	while (i < rows)
	{
		line = get_next_line(fd);
		game->map[i] = ft_strdup(line);
		if (ft_strchr(line, '\n'))
		 	game->map[i][ft_strlen(line) - 1] = '\0';
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}


char	**matrix_maker(char *argv, t_map *game)
{
	int 	fd;
	char 	*line;
	size_t	col;
	size_t	rows;

	rows = 0;
	col = 0;
	line = NULL;
	fd = open_file(argv);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (rows == 0)
			col = ft_strlen(line);
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	final_map(argv, rows, game);
	game->columns = col - 1;
    game->rows = rows;
	return(game->map);
}
