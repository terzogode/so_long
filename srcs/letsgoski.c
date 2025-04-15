/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgoski.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:13:49 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/15 19:00:30 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendering(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1' || game->map[y][x] == '0' \
				|| game->map[y][x] == 'E' || game->map[y][x] == 'C' \
				|| game->map[y][x] == 'P' || game->map[y][x] == 'G')
				letsfill(game, x, y);
			x++;
		}
		y++;
	}
}

void	letsfill(t_map *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.wall, x * PIX, y * PIX);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.floor, x * PIX, y * PIX);
	else if (game->map[y][x] == 'E') //non sta uscendo
		mlx_put_image_to_window(game->mlx, game->window,
			game->stat_exit, x * PIX, y * PIX);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.coll, x * PIX, y * PIX);
	else if (game->map[y][x] == 'P') //non sta morendo e non sta uscendo
		mlx_put_image_to_window(game->mlx, game->window,
			game->pg[game->idx_pg], x * PIX, y * PIX);
	else if (game->map[y][x] == 'G')
		mlx_put_image_to_window(game->mlx, game->window,
			game->gob[game->idx_gob], x * PIX, y * PIX);
}

void	letsgoski(t_map *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->columns * PIX,
			game->rows * PIX, "so_long");
	if (game->window == NULL)
		ft_printf("There's no map up here\n");
	if (game->window == NULL)
	{
		ft_printf("Failed map\n");
		exit (0);
	}
	initialize_img(game);
	rendering(game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
}
