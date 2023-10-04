/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:33:30 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/04 10:52:09 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	itright(t_complete *game, int e)
{
	int	x;

	x = itmove(game, game->n[e][0], game->n[e][1] + 1, e);
	if (x)
	{
		game->n[e][1]++;
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

void intellenemy(t_complete *game, int x)
{
	if (asimplechoise(game, x))
		return ;
	if(((game->steps % 2 ) && (game->f == 0)) || (!(game->steps % 2 ) &&  game->f))
	{
		if(orizontal (game, x))
			return ;
        return ;
	}
	if((!(game->steps % 2 ) && (game->f == 0)) || ((game->steps % 2 ) &&  game->f))
	{
		if(vertical(game, x))
			return ;
		return ;
	}
}


int orizontal(t_complete *game, int x)
{
	if (game->p1y > game->n[x][1])
	{
		if(orizontalright(game, x))
			return (1);
	}
	else if (game->p1y < game->n[x][1])
	{
		if(orizontaleft(game, x))
			return (1);
	}
	else
	    return (0);
    return(0);
}

int vertical(t_complete *game, int x)
{
	if (game->p1x > game->n[x][0])
	{
		if(verticaldown(game, x))
			return (1);
	}
	else if (game->p1x < game->n[x][0])
	{
		if(verticalup(game, x))
			return (1);
	}
	else
        return (0);
    return (0);
}

int asimplechoise(t_complete *game, int x)
{
	if (game->p1x == game->n[x][0])
	{
		if(orizontal(game, x))
			return (1);
		else
			return (0);
	}
	else if (game->p1y == game->n[x][1])
	{
		if(vertical(game, x))
			return (1);
		else
			return (0);
	}
	else
		return (0);
    return (0);
}
