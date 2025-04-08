/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:12:10 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/08 19:17:20 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Bruh, I can't open that");
		exit(1);
	}
	return (fd);
}

void	print_map(t_map *game) 
{
	size_t i;

	i = 0;
	while (i < game->rows)
	{
		ft_printf("%s", game->map[i]);
		i++;
	}
	ft_printf("\n");
}


size_t	lenchar(char *str, char s)
{
	int i;

	i = 0;
	while (str[i] != s)
	{
		i++;
	}
	return (i);
}
