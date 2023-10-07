/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/06 11:46:56 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	controls_working(int command, t_complete *game)
{
	if (command == 65307)
		exit_point(game);
	if (command == 119 || command == 65362)
		up(game);
	if (command == 115 || command == 65364)
		down(game);
	if (command == 97 || command == 65361)
		left(game);
	if (command == 100 || command == 65363)
		right(game);
	return (1);
}

int	exit_point(t_complete *game)
{
	int	a;

	a = -1;
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	while (game->map[++a])
		free(game->map[a]);
	free(game->map);
	a = 0;
	while (a < game->en)
		free(game->n[a++]);
	free(game->n);
	exit(0);
}
