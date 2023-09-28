/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/24 15:52:45 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	controls_working(int command,t_complete *game)
{
	ft_printf("il comando = %d", command);
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
	return (1);
}
