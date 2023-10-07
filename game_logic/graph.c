/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:12:59 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/07 11:58:25 by mcamilli         ###   ########.fr       */
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
	ifcenter2(game);
}

void	ifcenter2(t_complete *game)
{
	if (game->map[game->a][game->b] == '1')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->barrier, game->d * 100, game->c * 100);
	if (game->map[game->a][game->b] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->collectable, game->d * 100, game->c * 100);
	playerframe(game);
	if (game->map[game->a][game->b] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->exit, game->d * 100, game->c * 100);
	if (game->map[game->a][game->b] == '0')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->floor, game->d * 100, game->c * 100);
	enemyframe(game);
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/pavimento.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/muro.xpm", &i, &j);
	game->playerdown = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/playerdown.xpm", &i, &j);
	game->playerup = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/playerup.xpm", &i, &j);
	game->playerleft = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/playerleft.xpm", &i, &j);
	game->playerright = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/playerright.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/Portaopen.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/vaccine.xpm", &i, &j);
	game->enemyf1 = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/enemyf1.xpm", &i, &j);
	game->enemyf2 = mlx_xpm_file_to_image(game->mlx,
			"solongsprites/enemyf2.xpm", &i, &j);
}

void	adding_in_graphics_aroundp(t_complete *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	game->c = 0;
	game->d = 0;
	game->a = game->p1x - game->cin;
	while (game->c < game->winh)
	{
		game->b = game->p1y - game->cin;
		game->d = 0;
		while (game->d < game->winw)
		{
			ifcenter(game);
			game->d++;
			game->b++;
		}
		game->c++;
		game->a++;
	}
	printinfo(game);
}

void	enemyframe(t_complete *game)
{
	if (game->map[game->a][game->b] == 'N')
	{
		if (game->ed == 0)
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->enemyf1, game->d * 100, game->c * 100);
		else
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->enemyf2, game->d * 100, game->c * 100);
	}
}
