/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:35:17 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/20 18:28:04 by mcamilli         ###   ########.fr       */
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
        return (1) 
   }
   if (game->map[mx][my] == "C")
    {
        game->map[mx][my] = game->map[x][y];
        game->map[x][y] = "0";
        game->steps++
        game->coins++
        return (1);
   }
   if (game->map[mx][my] == "P")
    {
        game->map[mx][my] = game->map[x][y];
        game->map[x][y] = "0";
        game->steps++
        return (2)
   }
   return(0);
}

int up(t_complete *game)
{
     int x

     x = 0;
     x = youmove(game,game->P1x,game->P1y, game->P1x-1, game->P1y);
     game->P1x--;
     return(x);
}

int down(t_complete *game)
{
     int x

     x = 0;
     x = youmove(game,game->P1x,game->P1y, game->P1x+1, game->P1y);
     game->P1x++;
     return(x);
}


int left(t_complete *game)
{
     int x

     x = 0;
     x = youmove(game,game->P1x,game->P1y, game->P1x, game->P1y-1);
     game->P1y--;
     return(x);
}

int right(t_complete *game)
{
     int x

     x = 0;
     x = youmove(game,game->P1x,game->P1y, game->P1x, game->P1y+1);
     game->P1y++;
     return(x);
}
