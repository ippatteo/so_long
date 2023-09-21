/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_loong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:49:43 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/21 15:21:23 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int main(int ac, char **av)
{
    t_complete game;
    
    if (startgame(ac, av, &game))
    {
        printmap(game.map, &game);
    }
    else
        return (0);
    return (0);   
}