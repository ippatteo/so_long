/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:33:53 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/29 09:41:47 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int verticaldown(t_complete *game, int x)
{
	int z;
	
	z = 0;
	if(itdown(game, x))
	{
		checkprox(game, x);
			return (1);
	}
	else if(game->p1y < game->n[x][1])
		z = verticalorizontaleft(game, x);
	else if (game->p1y > game->n[x][1])
		z = verticalorizontalright(game, x);
	else if (game->p1y == game->n[x][1] && !(game->steps % 2))
		z = verticalorizontaleft(game, x);
	else if (game->p1y == game->n[x][1] && (game->steps % 2))
		z = verticalorizontalright(game, x);
	else
		z = itup(game, x);
	if (z)
		checkprox(game, x);
	return (z);
}

int verticalorizontalright(t_complete *game, int x)
{
	else if	(itright(game, x))
	{
		return (1);
	}
	else if(itup(game, x))
	{
		return (1);
	}
	else if(itdown(game, x))
	{
		return (1);
	}
	if(itleft(game, x))
	{
		return (1;)
	}
		return (0);
}


int verticalorizontaleft(t_complete *game, int x)
{
	if(itleft(game, x))
	{
		return (1);
	}
	else if(itup(game, x))
	{
		return (1);
	}
	else if(itdown(game, x))
	{
		return (1);
	}
	else if	(itright(game, x))
	{
		return (1);
	}
	else
		return (0);
}

int	verticalup(t_complete *game, int x)
{
	int z;
	
	z = 0;
	if(itup(game, x))
	{
		checkprox(game, x);
			return (1);
	}
	else if(game->p1y < game->n[x][1])
		z = verticalorizontaleft(game, x);
	else if (game->p1y > game->n[x][1])
		z = verticalorizontalright(game, x);
	else if (game->p1y == game->n[x][1] && !(game->steps % 2))
		z = verticalorizontaleft(game, x);
	else if (game->p1y == game->n[x][1] && (game->steps % 2))
		z = verticalorizontalright(game, x);
	else
		z = itdown(game, x);
	if (z)
		checkprox(game, x);
	return (z);
}

int orizontaleft(t_complete *game, int x)
{
	int z;
	
	z = 0;
	else if (itleft(game, x))
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
		z = itright(game, x);
	if(z)
		checkprox(game, x);
	return (z);
}