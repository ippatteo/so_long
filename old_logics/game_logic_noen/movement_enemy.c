/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:35:17 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/28 19:51:23 by mcamilli         ###   ########.fr       */
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

void	right(t_complete *game)
{
	int	x;

	x = itmove(game, game->n1x, game->n1y + 1);
	if (x)
	{
		game->n1y++;
	}
	if (x == 2)
	{
		ft_printf("hai perso\n");
		exit_point(game);
		return ;
	}
	return ;
}
