/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:31:56 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/29 09:40:20 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	turnoffn(t_complete *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == 'N')
				game->map[a][b] = '0';
			b++;
		}
		a++;
	}
	return ;
}

int	itmove(t_complete *game, int mx, int my, int e)
{
	if (game->map[mx][my] == '0')
	{
		game->map[mx][my] = game->map[game->n[e][0]][game->n[e][1]];
		game->map[game->n[e][0]][game->n[e][1]] = '0';
		return (1);
	}
	if (game->map[mx][my] == 'P')
	{
		game->map[mx][my] = game->map[game->n[e][0]][game->n[e][1]];
		return (2);
	}
	return (0);
}

int	itup(t_complete *game, int e)
{
	int	x;

	x = itmove(game, game->n[e][0] - 1, game->n[e][1], e);
	if (x)
	{
		game->n[e][0]--;
		return (1);
	}
	if (x == 2)
	{
		ft_printf("hai perso\n");
		exit_point(game);
		return (1);
	}
	return (0);
}

int	itdown(t_complete *game, int e)
{
	int	x;

	x = itmove(game, game->n[e][0] + 1, game->n[e][1], e);
	if (x)
	{
		game->n[e][0]++;
		return (1);
	}
	if (x == 2)
	{
		ft_printf("hai perso\n");
		exit_point(game);
		return (1);
	}
	return (0);
}

int	itleft(t_complete *game, int e)
{
	int	x;

	x = itmove(game, game->n[e][0], game->n[e][1] - 1, e);
	if (x)
	{
		game->n[e][1]--;
		return (1);
	}
	if (x == 2)
	{
		ft_printf("hai perso\n");
		exit_point(game);
		return (1);
	}
	return (0);
}
