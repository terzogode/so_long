/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:12:10 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/10 14:30:28 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_file(char *argv, t_map *game)
{
	game->fd = open(argv, __O_DIRECTORY);
	if (game->fd != -1)
	{
		ft_printf("No ti prego le cartelle no\n");
		close(game->fd);
		exit(1);
	}
	game->fd = open(argv, O_RDONLY);
	if (game->fd == -1)
	{
		ft_printf("Bruh, I can't open that\n");
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

size_t	lenchar(char *str, char s)
{
	int	i;

	i = 0;
	while (str[i] != s)
	{
		i++;
	}
	return (i);
}
