/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/30 01:08:38 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	controls_working(int command, t_complete *game)
{
    ft_printf("comando = %d", command);
	if (command == 65307)
		exit_point(game);
	if (command == 119)
		up(game);
	if (command == 115)
		down(game);
	if (command == 97)
		left(game);
	if (command == 100)
		right(game);
    if (command == 32)
		activateenemy(game);
	return (1);
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
	if (game->n)
		free(game->n);
	exit(0);
}
