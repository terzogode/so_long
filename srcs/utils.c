/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:12:10 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/14 23:27:26 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_file(char *argv, t_map *game)
{
	game->fd = open(argv, __O_DIRECTORY);
	if (game->fd != -1)
	{
		ft_printf("Bruh, are you really trying to open a folder as a map?\n");
		close(game->fd);
		exit(1);
	}
	game->fd = open(argv, O_RDONLY);
	if (game->fd == -1)
	{
		ft_printf("Can't touch this\n");
		exit(1);
	}
}

void	print_map(t_map *game)
{
	size_t	i;

	i = 0;
	while (i < game->rows)
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
}
