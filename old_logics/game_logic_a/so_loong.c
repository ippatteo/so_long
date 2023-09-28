/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_loong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:49:43 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/24 15:37:13 by mcamilli         ###   ########.fr       */
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
		game.mlx = mlx_init();
		place_images_in_game(&game);
		if (game.widht < 18 || game.height < 18)
		{
			game.mlx_win = mlx_new_window(game.mlx, (game.width * 50), 
					(game.height) * 50, "solong");
			adding_in_graphics(&game);
		}
		else
		{
			game.mlx_win = mlx_new_window(game.mlx, (10 * 50), 
					(game.height) * 50, "solong");
			adding_in_graphicsaroundp(&game);
		}	
		mlx_key_hook(game.mlx_win, controls_working, &game);
		mlx_hook(game.mlx_win, 17, 0, (void *)exit_point, 0);
		mlx_loop(game.mlx);
	}
	else
		return (0);
	return (0); 
}
