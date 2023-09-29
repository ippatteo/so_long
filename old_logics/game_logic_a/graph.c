/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:12:59 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/24 15:44:08 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	iffone(t_complete *game, int a, int b)
{
	if (game->map[a][b] == '1')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->barrier, b * 50, a * 50);
	if (game->map[a][b] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->collectable, b * 50, a * 50);
	if (game->map[a][b] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->player, b * 50, a * 50);
	if (game->map[a][b] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->exit, b * 50, a * 50);
	if (game->map[a][b] == '0')
		mlx_put_image_to_window(game->mlx, 
			game->mlx_win, game->floor, b * 50, a * 50);
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx,
			"game_images/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlx,
			"game_images/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"game_images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"game_images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx,
			"game_images/item.xpm", &i, &j);
}

void	adding_in_graphics_aroundp(t_complete *game)
{
	int	a;
	int	b;
	int c;
	int	d; 

	c = game->p1x
	d = game->p1y
	if (game->p1x < 10)
		c = 10;
	if (game->p1y < 10)
		d = 10;
	a = c - 10;
	while (a < c + 11)
	{
		b = d - 10;
		while (b < d  + 11)
		{
			iffone(game, a, b);
			b++;
		}
		a++;
	}
}

if (game->p1x < 10)
a = 0
while (a <11)
	{
		b = game->p1x - 10;
		while (b < game->p1x + 11)
		{
			iffone(game, a, b);
			b++;
		}
		a++;
	}

if (game->p1y < 10)
{
	a = game->p1x - 10;
	while (a < game->p1x + 11)
	{
		b = 0;
		while (b < 11)
		{
			iffone(game, a, b);
			b++;
		}
		a++;
	}
}






otherwalls = 




void	adding_in_graphics(t_complete *game)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			iffone(game, a, b);
			b++;
		}
		a++;
	}
	ft_printf("hai fatto %d passi\n", game->steps);
	ft_printf("ti mancano %d coins\n", game->coins);
}

int	exit_point(t_complete *game)
{
	int	a;

	a = 0;
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	while (a < game->height - 1)
		free(game->map[a++]);
	free(game->map);
	exit(0);
}