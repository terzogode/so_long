/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgoski.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:13:49 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/12 21:03:29 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{ 
		x = 0;
		while (game->map[y][x] != '\0') { // Itera sulle colonne
			if (game->map[y][x] == '1') // Muro
				mlx_put_image_to_window(game->mlx, game->window, game->img.wall, x * PIX, y * PIX);
			else if (game->map[y][x] == '0') // Pavimento
				mlx_put_image_to_window(game->mlx, game->window, game->img.floor, x * PIX, y * PIX);
			else if (game->map[y][x] == 'E') // Uscita
				mlx_put_image_to_window(game->mlx, game->window, game->img.exit, x * PIX, y * PIX);
			else if (game->map[y][x] == 'C') // Collezionabile
				mlx_put_image_to_window(game->mlx, game->window, game->img.coll, x * PIX, y * PIX);
			else if (game->map[y][x] == 'P') // Giocatore
				mlx_put_image_to_window(game->mlx, game->window, game->img.player, x * PIX, y * PIX);
			x++;
		}
		y++;
	}
}

void	initialize_images(t_map *game) 
{
	int	h;
	h = '32';
    game->img.wall = mlx_xpm_file_to_image(game->mlx, "sprite/wall.xpm", &h, &h);
    game->img.floor = mlx_xpm_file_to_image(game->mlx, "sprite/floor.xpm", &h, &h);
    game->img.exit = mlx_xpm_file_to_image(game->mlx, "sprite/exit.xpm", &h, &h);
    //game->img.coll = mlx_xpm_file_to_image(game->mlx, "sprite/player.xpm", NULL, NULL);
    game->img.player = mlx_xpm_file_to_image(game->mlx, "sprite/player.xpm", &h, &h);

    if (!game->img.wall|| !game->img.floor || !game->img.exit || !game->img.player) 
	{
        write(2, "Errore: Immagini non caricate correttamente\n", 44);
        exit(1);
    }
}


void	letsgoski(t_map *game)
{
	print_map(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->rows * PIX,
		game->columns * PIX, "so_long");
	if (game->window == NULL)
		ft_printf("There's no map up here\n");
	if (!game->window)
	{
		ft_printf("Failed map\n");
		exit (0);
	}
	initialize_images(game);
	//init_map(game);
	mlx_loop(game->mlx);
}


