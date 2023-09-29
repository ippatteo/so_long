/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:12:59 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/29 13:19:53 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ifcenter(t_complete *game, int a, int b)
{
	if (a < 0)
		a = 0;
	if (a > (game->height - 1))
		a = game->height - 1;
	if (b > (game->width - 1))
		b = game->width - 1;
	if (b < 0)
		b = 0;
	if (game->width < 10 || game->height < 10)
		turnoffn(game);
	ifcenter2(game, a, b);
}

void	ifcenter2(t_complete *game, int a, int b)
{
	if (game->map[a][b] == '1')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->barrier, game->d * 50, game->c * 50);
	if (game->map[a][b] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->collectable, game->d * 50, game->c * 50);
	if (game->map[a][b] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->player, game->d * 50, game->c * 50);
	if (game->map[a][b] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->exit, game->d * 50, game->c * 50);
	if (game->map[a][b] == '0')
		mlx_put_image_to_window(game->mlx, 
			game->mlx_win, game->floor, game->d * 50, game->c * 50);
	if (game->map[a][b] == 'N')
		mlx_put_image_to_window(game->mlx, 
			game->mlx_win, game->enemy, game->d * 50, game->c * 50);
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
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"game_images/enemy.xpm", &i, &j);
}

void	adding_in_graphics_aroundp(t_complete *game)
{
	int	a;
	int	b;

	game->c = 0;
	game->d = 0;
	a = game->p1x - 5;
	while (game->c < 11)
	{
		b = game->p1y - 5;
		game->d = 0;
		while (game->d < 11)
		{
			ifcenter(game, a, b++);
			game->d++;
		}
		game->c++;
		a++;
	}
	ft_printf("hai fatto %d passi\n", game->steps);
	ft_printf("ti mancano %d coins\n", game->coins);
    
}

/*void	adding_in_graphics(t_complete *game)
{
	int	a;
	int	b;

	a = 0;
	turnoffn(game);
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
}*/