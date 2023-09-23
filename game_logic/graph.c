/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:12:59 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/23 02:39:42 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void iffone(t_complete *game, int a, int b)
{
    if (game->map[a][b] == '1')
		mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->barrier, b * 40, a * 40);
	if (game->map[a][b] == 'C')
		mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->collectable, b * 40, a * 40);
	if (game->map[a][b] == 'P')
		mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->player, b * 40, a * 40);
	if (game->map[a][b] == 'E')
		mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->exit, b * 40, a * 40);
	if (game->map[a][b] == '0')
        mlx_put_image_to_window(game->mlx, 
        game->mlx_win, game->floor, b * 40, a * 40);
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
