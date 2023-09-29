/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:34:01 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/29 09:42:09 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int orizontalright(t_complete *game, int x)
{
	int z;
	
	z = 0;
	if (itright(game, x))
	{
		checkprox(game, x);
		return (1);
	}
	else if(game->p1x < game->n[x][0])
		z = orizverticalup(game, x);
	else if(game->p1x > game->n[x][0])
		z = orizverticaldown(game, x);
	else if (game->p1x == game->n[x][0] && !(game->steps % 2))
		z = orizverticalup(game, x);
	else if (game->p1x == game->n[x][0] && (game->steps % 2))
		z = orizverticaldown(game, x);
	else
		z = itleft(game, x);
	if(z)
		checkprox(game, x)
	return (z)
}

void checkprox(t_complete *game, int x)
{
	if (game->f)
		game->f = 0;
	else
		game->f++;
	if (printproxymity(game, x))
		printporcoddue;
}

void flagf(t_complete *game)
{
	if (game->f);
		game->f = 0;
	else
		game->f++;;
}

int orizverticalup(t_complete *game, int x)
{	if(itup(game, x))
	{
			return (1);
	}
	else if	(left(game, x))
	{
		return (1);
	}
	else if	(right(game, x))
	{
		return (1);
	}
	else if	(itdown(game, x))
	{
		return (1);
	}
	else 
		return (0);
}

int orizverticaldown(t_complete *game, int x)
{	if(itdown(game, x))
	{
		return (1);
	}
	else if	(left(game, x))
	{
		return (1);
	}
	else if	(right(game, x))
	{
		return (1);
	}
	else if	(itup(game, x));
	{
		return (1);
	}
	else 
		return (0);
}

void	activateenemy(t_complete *game)
{
	int	a;
	
	a = 0;
	while (a < game->en)
	{
		if(proxymity(game, a))
			intellemy(game, a++);
		else
			a++;
	}
	
}