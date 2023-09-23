/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:35:17 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/23 02:35:55 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	youmove(t_complete *game, int mx, int my)
{
	if (game->map[mx][my] == '0')
	{
		game->map[mx][my] = game->map[game->p1x][game->p1x];
		game->map[game->p1x][game->p1x] = '0';
		return (1);
	}
	if (game->map[mx][my] == 'C')
	{
		game->map[mx][my] = game->map[game->p1x][game->p1x];
		game->map[game->p1x][game->p1x] = '0';
		game->coins--;
		return (1);
	}
	if (game->map[mx][my] == 'P' && game->coins == 0)
	{
		game->map[mx][my] = game->map[game->p1x][game->p1x];
		game->map[game->p1x][game->p1x] = '0';
		return (2);
	}
	return (0);
}

void	up(t_complete *game)
{
	int	x;

	x = youmove(game, game->p1x - 1, game->p1x);
	if (x)
	{
		game->steps++;
		game->p1x--; 
		printmap(game->map, game);
		ft_printf("hai fatto %d passi\n", game->steps);
		ft_printf("ti mancano %d coins\n", game->coins);
	}
	if (x == 2)
	{
		ft_printf("hai vinto, daje\n");
		exit_point(game);
		return ;
	}
	return ;
}

void	down(t_complete *game)
{
	int	x;

	x = youmove(game, game->p1x + 1, game->p1x);
	if (x)
	{
		game->steps++;
		game->p1x++;
		printmap(game->map, game);
		ft_printf("hai fatto %d passi\n", game->steps);
		ft_printf("ti mancano %d coins\n", game->coins);
		 
	}
	if (x == 2)
	{
		ft_printf("hai vinto, daje\n");
		exit_point(game);
		return ;
	}
	return ;
}

void	left(t_complete *game)
{
	int	x;

	x = youmove(game, game->p1x, game->p1x - 1);
	if (x)
	{
		game->steps++;
		game->p1x--; 
		printmap(game->map, game);
		ft_printf("hai fatto %d passi\n", game->steps);
		ft_printf("ti mancano %d coins\n", game->coins);
	}
	if (x == 2)
	{
		ft_printf("hai vinto, daje\n");
		exit_point(game);
		return ;
	}
	return ;
}

void	right(t_complete *game)
{
	int	x;

	x = youmove(game, game->p1x, game->p1x + 1);
	if (x)
	{
		game->steps++;
		game->p1x++;
		printmap(game->map, game);
		ft_printf("hai fatto %d passi\n", game->steps);
		ft_printf("ti mancano %d coins\n", game->coins);
		 
	}
	if (x == 2)
	{
		ft_printf("hai vinto, daje\n");
		exit_point(game);
		return ;
	}
	return ;
}
