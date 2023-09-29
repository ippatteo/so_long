/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_loong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:49:43 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/29 18:42:20 by mcamilli         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_complete	game;
    game.en = 0;
	game.steps = 0;
    int intervalloMicrosecondi = 1000000; // Specifica l'intervallo in microsecondi (1 secondo = 1,000,000 microsecondi)
    int intervalloChiamataFunzione = 5;
	if (startgame(ac, av, &game))
	{
        takepositionenemy(&game);
        //ft_printf("coord %d %d di N\n", game.n[0][0], game.n[0][1]);
		game.mlx = mlx_init();
		place_images_in_game(&game);
		game.mlx_win = mlx_new_window(game.mlx, (10 * 50), 
				(10 * 50), "solong");
		adding_in_graphics_aroundp(&game);
        while(1)
        {
            mlx_hook(game.mlx_win, 17, 0, otherexit, NULL);
		    mlx_key_hook(game.mlx_win, controls_working, &game);
		    mlx_loop(game.mlx);
        }
    }
	else
		return (0);
	return (0); 
}
