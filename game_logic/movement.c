/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:35:17 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/15 16:29:20 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int youmove(t_complete *game, int x, int y, int mx, int my)
{
   if (game->map[mx][my] == "0")
   {
        game->map[mx][my] = game->map[x][y];
        game->map[x][y] = "0";
        game->steps++      
   }
   if (game->map[mx][my] == "c")
    {
        game->map[mx][my] = game->map[x][y];
        game->map[x][y] = "0";
        game->steps++
              
   }
}