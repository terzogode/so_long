/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:03 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/14 23:18:39 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(t_map *game, int err)
{
	if (err == E_EXTENSION)
	{
		ft_printf("If you don't use .ber I'm gonna use .berETTA\n");
		exit (1);
	}
	close(game->fd);
	if (err == E_EMPTY_MAP)
		ft_printf("I see no map up here\n");
	if (err == E_EXIT)
		ft_printf("Wanna play forever? You need to leave\n");
	if (err == E_PLAYER)
		ft_printf("Do you really want to play? You need a player\n");
	if (err == E_COLLECTIBLE)
		ft_printf("There's nothing to eat for the player, he's gonna die\n");
	if (err == E_MAP_DIMENSION)
		ft_printf("Come back to school to learn what a rectangle is\n");
	if (err == E_WALL)
		ft_printf("I understand you like open world, but you know I can't\n");
	if (err == E_IMAX)
		ft_printf("Go find yourself or at least a valid imax\n");
	free_maptrix(game, game->map);
	if (game->coll_check != NULL)
		free_maptrix(game, game->coll_check);
	exit (1);
}
