/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:35:17 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/29 03:05:50 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	itmove(t_complete *game, int mx, int my)
{
	if (game->map[mx][my] == '0')
	{
		game->map[mx][my] = game->map[game->n1x][game->n1y];
		game->map[game->n1x][game->n1y] = '0';
		return (1);
	}
	if (game->map[mx][my] == 'P')
	{
		game->map[mx][my] = game->map[game->n1x][game->n1y];
		return (2);
	}
	return (0);
}

void	up(t_complete *game)
{
	int	x;

	x = itmove(game, game->n1x - 1, game->n1y);
	if (x)
	{
		game->n1x--;
		adding_in_graphics_aroundp(game);

	}
	if (x == 2)
	{
		ft_printf("hai perso\n");
		exit_point(game);
		return ;
	}
	return ;
}

void	down(t_complete *game)
{
	int	x;

	x = itmove(game, game->n1x + 1, game->n1y);
	if (x)
	{
		game->n1x++;
	}
	if (x == 2)
	{
		ft_printf("hai perso\n");
		exit_point(game);
		return ;
	}
	return ;
}

void	left(t_complete *game)
{
	int	x;

	x = itmove(game, game->n1x, game->n1y - 1);
	if (x)
	{
		game->n1y--;
	if (x == 2)
	{
		ft_printf("hai perso\n");
		exit_point(game);
		return ;
	}
	return ;
    }  

} 

int	right(t_complete *game)
{
	int	x;

	x = itmove(game, game->n1x, game->n1y + 1);
	if (x)
	{
		game->n1y++;
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
	if((game->steps % 3 ) && game->f = 0 ||(game->steps % 3 ) &&  game->f = 1)
		{
			if (game->p1y > game->n[x][1])
				orizontalright(game, x);
			else if (game->p1y > game->n[x][1])
				orizontaleft(game, x);
		}
}
int orizontaleft(t_complete *game, x)
{
	int z;
	
	z = 0;
	
	else if (left(game))
	{
		checkprox(game, x)
		return (1);
	}
	if (right(game))
	{
		checkprox(game, x)
		return (1)
	}
	else if(game->p1x < game->n[x][0])
	{
		z = orizverticalup(game, x);
	}
	else
		z = orizverticaldown(game, x);
	return (z)
}

int orizontalright(t_complete *game, x)
{
	int z;
	
	z = 0;
	if (right(game))
	{
		checkprox(game, x)
		return (1)
	}
	else if (left(game))
	{
		checkprox(game, x)
		return (1);
	}
	else if(game->p1x < game->n[x][0])
	{
		z = orizverticalup(game, x);
	}
	else
		z = orizverticaldown(game, x);
	return (z)
}

void checkprox(t_complete *game, int x)
{
	game->f++	
	if (printproxymity(game, x))
		printporcoddue
}

int orizverticalup(t_complete *game, int x)
{	if(up(game))
	{
		checkprox(game, x)
			return (1)
	}
	else if	(down(game))
	{
		checkprox(game, x)
		return (1)
	}
	else 
		return (0);
}

int orizverticaldown(t_complete *game, int x)
{	if(down(game))
	{
		checkprox(game, x)
			return (1)
	}
	else if	(up(game))
	{
		checkprox(game, x)
		return (1)
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
			a++
	}
	
}

int takepositionenemy(t_complete *game)
{
	int	a;
	int	b;
	
	game->n = malloc(sizeof (int *) * (scan1(game, 'N') * 2));
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



int printproxymity(t_complete *game, int x)
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
			if(foundp(game, a, b))
				return (1)
			game->d++;
		}
		game->c++;
        a++;
	}
	return(0);
}

int proxymity(t_complete *game, int x)
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
			if(foundp(game, a, b))
				return (1)
			game->d++;
		}
		game->c++;
        a++;
	}
	return(0);
}

int foundp(t_complete *game, int a, int b)
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
		return(0);
}