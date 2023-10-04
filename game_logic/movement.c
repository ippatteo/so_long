/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:35:17 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/03 03:09:53 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	youmove(t_complete *game, int mx, int my)
{
	if (game->map[mx][my] == '0')
	{
		game->map[mx][my] = game->map[game->p1x][game->p1y];
		game->map[game->p1x][game->p1y] = '0';
		return (1);
	}
	if (game->map[mx][my] == 'C')
	{
		game->map[mx][my] = game->map[game->p1x][game->p1y];
		game->map[game->p1x][game->p1y] = '0';
		game->coins--;
		return (1);
	}
	if (game->map[mx][my] == 'E' && game->coins == 0)
		return (2);
	if (game->map[mx][my] == 'N')
	{
		ft_printf("hai perso\n");
		exit_point(game);
	}
	return (0);
}

int	up(t_complete *game)
{
	int	x;

	x = youmove(game, game->p1x - 1, game->p1y);
	if (x)
	{
		game->steps++;
		game->p1x--;
		adding_in_graphics_aroundp(game);
	}
	if (x == 2)
	{
		ft_printf("hai vinto, daje\n");
		exit_point(game);
		return (x);
	}
	return (x);
}

int	down(t_complete *game)
{
	int	x;

	x = youmove(game, game->p1x + 1, game->p1y);
	if (x)
	{
		game->steps++;
		game->p1x++;
		adding_in_graphics_aroundp(game);
	}
	if (x == 2)
	{
		ft_printf("hai vinto, daje\n");
		exit_point(game);
		return (x);
	}
	return (x);
}

int	left(t_complete *game)
{
	int	x;

	x = youmove(game, game->p1x, game->p1y - 1);
	if (x)
	{
		game->steps++;
		game->p1y--;
		adding_in_graphics_aroundp(game);
	}
	if (x == 2)
	{
		ft_printf("hai vinto, daje\n");
		exit_point(game);
		return (x);
	}
	return (x);
}

int	right(t_complete *game)
{
	int	x;

	x = youmove(game, game->p1x, game->p1y + 1);
	if (x)
	{
		game->steps++;
		game->p1y++;
		adding_in_graphics_aroundp(game);
	}
	if (x == 2)
	{
		ft_printf("hai vinto, daje\n");
		exit_point(game);
		return (x);
	}
	return (x);
}
