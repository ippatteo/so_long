/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:34:07 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/29 09:44:17 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	takepositionenemy(t_complete *game)
{
	int	a;
	int	b;

	game->en = scan1(game, 'N');
	game->n = malloc(sizeof (int *) * (game->en * 2));
	if (!game->n)
		return (0);
	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == 'N')
			{
				game->n[game->en][0] = a;
				game->n[game->en++][1] = b;
			}
			b++;
		}
		a++;
	}
	return (game->en);
}

int	printproxymity(t_complete *game, int x)
{
	int	a;
	int	b;

	game->c = 0;
	game->d = 0;
	a = game->n[x][0] - 5;
	while (game->c < 11)
	{
		b = game->n[x][1] - 5;
		game->d = 0;
		while (game->d < 11)
		{
			if (foundp(game, a, b))
				return (1);
			game->d++;
		}
		game->c++;
		a++;
	}
	return (0);
}

int	proxymity(t_complete *game, int x)
{
	int	a;
	int	b;

	game->c = 0;
	game->d = 0;
	a = game->n[x][0] - 10;
	while (game->c < 21)
	{
		b = game->n[x][1] - 10;
		game->d = 0;
		while (game->d < 21)
		{
			if (foundp(game, a, b))
				return (1);
			game->d++;
		}
		game->c++;
		a++;
	}
	return (0);
}

int	foundp(t_complete *game, int a, int b)
{
	if (a < 0)
		a = 0;
	if (a > (game->height - 1))
		a = game->height - 1;
	if (b > (game->width - 1))
		b = game->width - 1;
	if (b < 0)
		b = 0;
	if (game->map[a][b] == 'P')
		return (1);
	else
		return (0);
}
