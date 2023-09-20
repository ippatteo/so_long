/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:00:30 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/20 19:47:04 by mcamilli         ###   ########.fr       */
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
        while (game->map[a][b])
        {
            if (!(game->map[a][b] == "1" || game->map[a][b] == "C" || game->map[a][b] == "E" 
            || game->map[a][b] == "P" || game->map[a][b] == "0"))
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
    int p;

    a = 0;
    b = 0;
    e = 0;
    while (game->map[a])
    {
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
    int p;

    a = 0;
    b = 0;
    e = 0;
    while (game->map[a])
    {
        while (game->map[a][b])
        {
            if ((game->map[a][b] == c) &&
             ((a == 0) || (b == 0) || (a == game->height-1) ||
             (b == game->width-1)))
                e++;
            b++;
        }
        a++;
    }
    return (e);
}

int scanC(t_complete *game)
{
    int a;
    int b;

    a = 0;
    b = 0;
    if ((scan1(game,"C")))
    {
        game->coins = scan1(game,"C");
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
    if (game->height != game->width)
        return(0);
    while (game->map[a])
    {
        if (ft_strlen(game->map[a]) != b)
            return (0)
        a++;
    }
    return (1)
}

int megatroll(t_complete *game)
{
    if (scanwall(game, "1") != ((game->height + game->width - 1) * 2))
        return (0);
    if (!scanC(game))
        return (0);
    if ((scan1(game, "P") * scan1(game, "E")) != 1)
        return (0);
    if (!scanintrude(game) || !rectangular(game))
        return(0);
    if (!pathfind(game))
        return (0);
    return(1)
}