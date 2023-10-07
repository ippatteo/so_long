/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:22:08 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/07 11:50:55 by mcamilli         ###   ########.fr       */
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
	int	x;

	x = 0;
	ft_printf("hai fatto %d passi\n", game->steps);
	while (c[x])
	{
		ft_putstr(c[x]);
		write(1, "\n", 1);
		x++ ;
	}
}

void	whereisp(t_complete *game, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == c)
			{
				game->p1x = a;
				game->p1y = b;
				return ;
			}
			b++;
		}
		a++;
	}
	return ;
}

int	mapnroll(int ac, char **av, t_complete	*game)
{
	int			fd1;
	char		*line;

	if (ac == 2)
	{
		fd1 = open(av[1], O_RDONLY);
		if (fd1 == -1)
			return (0);
		line = get_next_file(fd1);
		game->height = getheight(line);
		game->map = ft_split(line, '\n');
		game->width = (int)ft_strlen(game->map[0]);
		free (line);
		if (!game->map)
			return (0);
		whereisp(game, 'P');
	}
	else
		return (0);
	return (1);
}

int	startgame(int ac, char **av, t_complete *game)
{
	if (!mapnroll(ac, av, game))
	{
		ft_printf("error: mappa non caricata\n");
		return (0);
	}
	if (!megatroll(game))
	{
		ft_printf("error: mappa sbagliata\n");
		return (0);
	}
	proportions(game);
	game->pd = 0;
	game->ed = 0;
	return (1);
}
