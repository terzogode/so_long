/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:03 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/08 18:38:29 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(t_map *game, int err)
{
	if (err == E_EXTENSION)
	{
		ft_printf("Error file extension");
		exit (1);
	}
	if (err == E_CHAR_ERROR)
		exit (1);
	if (err == E_PLAYER_OR_EXIT)
		ft_printf("Wrong number of player or exit");
	if (err == E_COLLECTIBLE)
		ft_printf("There must be at least one colletible");
	if (err == E_MAP_DIMENSION)
		ft_printf("Incorrect dimension of map");

	free_maptrix(game);
	exit (1);
}