/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:22:08 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/20 19:38:46 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	getheight(char *c)
{
	int	x;
	int	a;

	x = 0;
	a = 0;
	while (c[x++])
	{
		if (c[x] == '\n')
			a++;
	}
	a++;
	return (a);
}

void	printmap(char **c, t_complete *game)
{
	int x;
	
	x = 0;
	ft_printf("hai fatto %d passi\n", game->steps);
	while (c[x])
	{
		ft_putstr(c[x]);
		write(1, "\n", 1);
		x++;    
	}	
}

void whereisP(t_complete *game, char C)
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
            {
				game->P1x = a;
				game->P1y = b;
				return;
			}
            b++;
        }
        a++;
    }
    return;
}

int	mapread(int ac, char **av, t_complete	*game)
{
	int			fd1;
	char		*line;

	if (ac == 2)
	{
		fd1 = open(av[1], O_RDONLY);
		line = get_next_file(fd1);
		game->height = getheight(line);
		game->map = ft_split(line, '\n');
		game->width = ft_strlen(game->map[0]);
		free (line);
		if (!game->map)
			return (0);
	}
	else
		return (0);
	return (1);
}