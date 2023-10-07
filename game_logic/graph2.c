/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:27:20 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/07 11:47:36 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	playerframe(t_complete *game)
{
	if (game->map[game->a][game->b] == 'P')
	{
		if (game->pd == 0)
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->playerdown, game->d * 100, game->c * 100);
		else if (game->pd == 1)
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->playerup, game->d * 100, game->c * 100);
		else if (game->pd == 2)
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->playerright, game->d * 100, game->c * 100);
		else if (game->pd == 3)
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->playerleft, game->d * 100, game->c * 100);
	}
}

void	printinfo(t_complete *game)
{
	char	*x;

	x = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->mlx_win,
		20, (game->winh * 100 + 15), 0xFFFFFF,
		"HAI FATTO     PASSI,   TI MANCANO     CURE");
	mlx_string_put(game->mlx, game->mlx_win,
		80, (game->winh * 100 + 15), 0xFFFFFF, x);
	free(x);
	x = ft_itoa(game->coins);
	mlx_string_put(game->mlx, game->mlx_win,
		225, (game->winh * 100 + 15), 0xFFFFFF, x);
	free(x);
}
