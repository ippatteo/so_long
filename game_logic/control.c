/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:00:30 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/21 21:03:51 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int scanintrude(t_complete *game)
{
    int a;
    int b;

    a = 0;
    b = 0;
    while (game->map[a])
    {
        b = 0;
        while (game->map[a][b])
        {
            if (!(game->map[a][b] == '1' || game->map[a][b] == 'C' || game->map[a][b] == 'E' 
            || game->map[a][b] =='P' || game->map[a][b] == '0'))
                return (0);
            b++;
        }
        a++;
    }
    return (1);
}

int scan1(t_complete *game, char c)
{
    int a;
    int b;
    int e;

    a = 0;
    b = 0;
    e = 0;
    while (game->map[a])
    {
        b = 0;
        while (game->map[a][b])
        {
            if (game->map[a][b] == c)
                e++;
            b++;
        }
        a++;
    }
    return (e);
}

int scanwall(t_complete *game, char c)
{
    int a;
    int b;
    int e;

    a = 0;
    b = 0;
    e = 0;
    while (game->map[a])
    {   b = 0;
        while (game->map[a][b])
        {
            if ((game->map[a][b] == c) && (b == 0 || b == game->width - 1 || a == 0 || a == game->height - 1))
                e++;
            b++;
        }
       
        a++;
    }
    return (e);
}

int scanC(t_complete *game)
{
    
    game->coins = scan1(game,'C');
    if ((game->coins))
    {
        return (1);
    }
    else
        return (0);
}

int rectangular(t_complete *game)
{
    int a;
    int b;

    a = 0;
    b = ft_strlen(game->map[a]);
    if (game->height == game->width)
        return(0);
    while (game->map[a])
    {
        if ((int)ft_strlen(game->map[a]) != b)
            return (0);
        a++;
    }
    return (1);
}

int megatroll(t_complete *game)
{
    /*if (scanwall(game, '1') != ((game->height + game->width - 2) * 2))
        return (1);
    if (!scanC(game))
        return (1);
    if ((scan1(game, 'P') * scan1(game, 'E')) != 1)
        return (1);
    if (!scanintrude(game))
        return(1);
    if (!rectangular(game))
        return (1);*/
    if (!pathfind(game))
        return (0);
    return(1);
}