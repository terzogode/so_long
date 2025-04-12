/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:32:47 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/12 20:45:30 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	game = (t_map){0};
	if (argc != 2)
	{
		ft_printf("Error: wrong numbers of arguments");
		exit(1);
	}
	checker(argv[1], &game);
	//free_maptrix(&game);
	letsgoski(&game);
	return (0);
}

