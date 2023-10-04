/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_loong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:49:43 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/05 01:39:07 by mcamilli         ###   ########.fr       */
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

int	otherexit(void)
{
	exit(0);
}

int	enemove(t_complete *game)
{
	static int	time;
    int a;

    a = 0;
	if (time == 20000)
	{
        takepositionenemy(game);
		activateenemy(game);
		time = 0;
        a = 0;
	    while (a < game->en - 1)
		    free(game->n[a++]);
        free(game->n);
	}
	time++;
	return (0);
}
int	main(int ac, char **av)
{
	t_complete	game;
	game.steps = 0;
    game.pd = 0;
    game.ed = 0;
	if (startgame(ac, av, &game))
	{
		game.mlx = mlx_init();
		place_images_in_game(&game);
		game.mlx_win = mlx_new_window(game.mlx, (10 * 100), 
				(10 * 100 + 20), "solong");
		adding_in_graphics_aroundp(&game);
        mlx_hook(game.mlx_win, 17, 0, otherexit, NULL);
        mlx_key_hook(game.mlx_win, controls_working, &game);
        mlx_loop_hook(game.mlx, enemove, &game);
        mlx_loop(game.mlx);
    }
    
    return (0);
}
