/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappe2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:51:22 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/06 11:51:54 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	proportions(t_complete *game)
{
	if (game->height < 12)
		game->winh = game->height;
	if (game->width < 12)
		game->winw = game->width;
	if (game->height < 12 || game->width < 12)
		game->cin = 2;
}
