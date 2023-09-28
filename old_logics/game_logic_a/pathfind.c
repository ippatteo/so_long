/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:47:16 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/22 13:52:20 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	sq(t_complete *game, int x, int y, char a)
{
	if (game->map[x][y - 1] == a || game->map[x - 1][y] == a ||
	game->map[x][y + 1] == a || game->map[x + 1][y] == a)
		return (1);
	else
		return (0);
}

void	changeit(t_complete *game, int a, int b)
{
	if (game->map[a][b] == '0')
		game->map[a][b] = '2';
	else if (game->map[a][b] == '2')
		game->map[a][b] = '0';
	if (game->map[a][b] == 'E')
		game->map[a][b] = 'U';
	else if (game->map[a][b] == 'U')
		game->map[a][b] = 'E';
	if (game->map[a][b] == 'C')
		game->map[a][b] = 'S';
	else if (game->map[a][b] == 'S')
		game->map[a][b] = 'C';
	return ;
}

int	controlpath(t_complete *game)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if ((game->map[a][b] == '0' || game->map[a][b] == 'E' ||
			game->map[a][b] == 'C') && (sq(game, a, b, 'P') || 
			sq(game, a, b, '2') || sq(game, a, b, 'U') || sq(game, a, b, 'S')))
			{
				changeit(game, a, b);
				return (controlpath(game));
			}
			b++;
		}
		a++;
	}
	return (0);
}

int	scan(t_complete *game)
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
			if (game->map[a][b] == 'C' || game->map[a][b] == 'E')
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	pathfind(t_complete *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	controlpath(game);
	if (scan(game))
	{
		while (game->map[a])
		{
			b = 0;
			while (game->map[a][b])
			{
				if (game->map[a][b] == '2' || game->map[a][b] == 'S' ||
				game->map[a][b] == 'U')
					changeit(game, a, b);
				b++;
			}
			a++;
		}
		return (1);
	}
	else
		return (0);
}
