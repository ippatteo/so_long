/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_loong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:49:43 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/22 17:59:44 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	megatroll(t_complete *game)
{
	if (scanwall(game, '1') != ((game->height + game->width - 2) * 2))
		return (0);
	if (!scanc(game))
		return (0);
	if ((scan1(game, 'P') * scan1(game, 'E')) != 1)
		return (0);
	if (!scanintrude(game))
		return (0);
	if (!rectangular(game))
		return (0);
	if (!pathfind(game))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_complete	game;

	game.steps = 0;
	if (startgame(ac, av, &game))
	{
		printmap(game.map, &game);
		
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx, (game.width * 40), (game.width) * 40, "solong");
		mlx_loop(game.mlx);
	}
	else
		return (0);
	return (0); 
}
