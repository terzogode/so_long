/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:07 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/08 19:19:10 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker(char *argv, t_map *game)
{
	//int i = 0;
	check_extension(argv, game);
	matrix_maker(argv, game);
	check_dimension(game);
	check_char(game);
	check_player_exit(game);
	check_coll(game);
	//printf("%zu\n", game->rows);
	//printf("%zu\n", game->columns);
	//printf("%zu\n",ft_strlen(game->map[i]));
	print_map(game);
}

void	check_dimension(t_map *game)
{
	size_t	i;

	i = 0;
	while (i < game->rows)
	{
		printf("%zu\n", game->columns);
		printf("%zu\n",lenchar(game->map[i], '\n'));
		if (lenchar(game->map[i], '\n') != game->columns)
			errors(game, E_MAP_DIMENSION);
		i++;
	}
	//printf("row: %zu\n", game->rows);
	//if (i != game->rows)
		//errors(game, E_MAP_DIMENSION);
}
int	check_extension(char *arg, t_map *game)
{
	int		i;
	char	*ext;
	int		ext_idx;

	ext_idx = 0;
	ext = ".ber";
	i = 0;
	while (arg[i] != '\0')
	{
		i++;
	}
	i = i - 4;
	while (ext_idx <= 4 && (arg[i] != '\0' && ext[ext_idx] != '\0'))
	{
		if (arg[i] != ext[ext_idx])
			errors(game, E_EXTENSION);
		ext_idx++;
		i++;
	}
	return (1);
}
