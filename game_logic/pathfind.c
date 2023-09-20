/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:47:16 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/20 19:38:49 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int sq(t_complete *game, int x, int y, char a)
{
    if ( game->map[x][y-1] == a || game->map[x-1][y] == a || game->map[x][y+1] == a || game->map[x+1][y] == a)
        return (1);
    else
        return (0);
}

void changeit(char c)
{
    if (c == "0")
        c = "2";
    if (c == "E")
        c = "U";
    if (c == "C")
        c = "S";
    if (c == "2")
        c = "0";
    if (c == "U")
        c = "E";
    if (c == "S")
        c = "C";
    return;
}


int controlpath(t_complete *game)
{
    int a;
    int b;

    a = 0;
    b = 0;
    while (game->map[a])
    {
        while (game->map[a][b])
        {
            if (game->map[a][b] == "1" || game->map[a][b] "P")
                b++;
            if (sq(game, a, b, "P") || sq(game, a, b, "2") || sq(game, a, b, "U") || sq(game, a, b, "S"))
            {
                if (game->map[a][b] == "0" || game->map[a][b] == "C" || game->map[a][b] == "E")
                {
                    changeit(game->map[a][b]);
                    return (controlpath(game));
                }
            }
        }
        a++;
    }
    return (0);
}

int scan (t_complete *game)
{
    int a;
    int b;

    a = 0;
    b = 0;
    while (game->map[a])
    {
        while (game->map[a][b])
        {
            if (game->map[a][b] == "C" || game->map[a][b] == "E")
                return (0);
            b++;
        }
        a++;
    }
    return (1);
}

int pathfind(t_complete *game)
{
    int a;
    int b;

    a = 0;
    b = 0;
    controlpath(game);
    if (scan(game))
    {
        while (game->map[a])
        {
            while (game->map[a][b])
            {
                if (game->map[a][b] == "2" || game->map[a][b] == "S" || game->map[a][b] == "U")
                    changeit(game->map[a][b]);
                b++;
            }
            a++;
        }
        return (1);
    }
    else
        return (0);
}