/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:12:59 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/02 20:00:15 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ifcenter(t_complete *game)
{
	if (game->a < 0)
		game->a = 0;
	if (game->a > (game->height - 1))
		game->a = game->height - 1;
	if (game->b > (game->width - 1))
		game->b = game->width - 1;
	if (game->b < 0)
		game->b = 0;
	if (game->width < 10 || game->height < 10)
		turnoffn(game);
	ifcenter2(game);
}

void	ifcenter2(t_complete *game)
{
	if (game->map[game->a][game->b] == '1')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->barrier, game->d * 50, game->c * 50);
	if (game->map[game->a][game->b] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->collectable, game->d * 50, game->c * 50);
	if (game->map[game->a][game->b] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->player, game->d * 50, game->c * 50);
	if (game->map[game->a][game->b] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->exit, game->d * 50, game->c * 50);
	if (game->map[game->a][game->b] == '0')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->floor, game->d * 50, game->c * 50);
	if (game->map[game->a][game->b] == 'N')
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
	game->c = 0;
	game->d = 0;
	game->a = game->p1x - 5;
	while (game->c < 11)
	{
		game->b = game->p1y - 5;
		game->d = 0;
		while (game->d < 11)
		{
			ifcenter(game);
			game->d++;
			game->b++;
		}
		game->c++;
		game->a++;
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