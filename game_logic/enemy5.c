/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:34:07 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/05 01:47:39 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	activateenemy(t_complete *game)
{
	int	a;
	
	a = 0;
	while (a < game->en)
	{
        if(proxymity(game, a))
        {
            intellenemy(game, a);
        }
        a++;
    }
}   

void takepositionenemy(t_complete *game)
{
	int	a;
	int	b;

    game->en = 0;
	game->n = (int **)ft_calloc(sizeof(int *), scan1(game, 'N'));
	if (!game->n)
		return ;
    while(game->en < scan1(game, 'N'))
    {
         game->n[game->en] = (int *)ft_calloc(sizeof(int), 2);
        if (!game->n[game->en])
            return ;
        game->en++;
    }
    
    game->en = 0;
	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{   
			if (game->map[a][b] == 'N')
			{
				game->n[game->en][0] = a;
				game->n[game->en][1] = b;
                game->en++;
		    }
            b++;
	    }
        a++;
    }
}

int	printproxymity(t_complete *game, int x)
{
	int	a;
	int	b;

	game->z = 0;
	a = game->n[x][0] - 5;
	while (game->z < 11)
	{
		b = game->n[x][1] - 5;
		game->t = 0;
		while (game->t < 11)
		{
			if (foundp(game, a, b++))
				return (1);
			game->t++;
		}
		game->z++;
		a++;
	}
	return (0);
}

int	proxymity(t_complete *game, int x)
{
	int	a;
	int	b;

	game->z = 0;
	game->t = 0;
	a = game->n[x][0] - 10;
	while (game->z < 21)
	{
		b = game->n[x][1] - 10;
		game->t = 0;
		while (game->t < 21)
		{
			if (foundp(game, a, b++))
				return (1);
			game->t++;
		}
		game->z++;
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
