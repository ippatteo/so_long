/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:08:37 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/29 15:26:10 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../printf/ft_printf.h"

typedef struct t_start
{
    int     z;
    int     t;
	int		f;
	int		en;
	int		n1x;
	int		n1y;
	int		c;
	int		d;
	int		p1y;
	int		p1x;
	int		steps;
	int		width;
	int		height;
	int		coins;
	int		**n;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*floor;
	void	*enemy;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
}	t_complete;

void	ifcenter2(t_complete *game, int a, int b);
int		foundp(t_complete *game, int a, int b);
int		proxymity(t_complete *game, int x);
int		printproxymity(t_complete *game, int x);
void takepositionenemy(t_complete *game);
void	activateenemy(t_complete *game);
int		orizverticaldown(t_complete *game, int x);
int		orizverticalup(t_complete *game, int x);
void	flagf(t_complete *game);
void	checkprox(t_complete *game, int x);
int		orizontalright(t_complete *game, int x);
int		orizontaleft(t_complete *game, int x);
int		verticalup(t_complete *game, int x);
int		verticalorizontaleft(t_complete *game, int x);
int		verticalorizontalright(t_complete *game, int x);
int		verticaldown(t_complete *game, int x);
int		asimplechoise(t_complete *game, int x);
int		vertical(t_complete *game, int x);
int		orizontal(t_complete *game, int x);
void	intellenemy(t_complete *game, int x);
int		itright(t_complete *game, int e);
int		itleft(t_complete *game, int e);
int		itdown(t_complete *game, int e);
int		itup(t_complete *game, int e);
int		itmove(t_complete *game, int mx, int my, int e);
void	turnoffn(t_complete *game);
//void	iffone(t_complete *game, int a, int b);
void	adding_in_graphics_aroundp(t_complete *game);
int		controls_working(int command, t_complete *game);
int		exit_point(t_complete *game);
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
void	ifcenter(t_complete *game, int c, int d);
int		pathfind(t_complete *game);
int		startgame(int ac, char **av, t_complete *game);
void	changeit(t_complete *game, int a, int b);
int		scan(t_complete *game);
int		controlpath(t_complete *game);
int		sq(t_complete *game, int x, int y, char a);
void	right(t_complete *game);
void	left(t_complete *game);
void	down(t_complete *game);
void	up(t_complete *game);
void	whereisp(t_complete *game, char C);
int		getheight(char *c);
void	printmap(char **c, t_complete *game);
int		mapnroll(int ac, char **av, t_complete	*game);
int		youmove(t_complete *game, int mx, int my);
int		scanintrude(t_complete *game);
int		scan1(t_complete *game, char c);
int		scanwall(t_complete *game, char c);
int		scanc(t_complete *game);
int		rectangular(t_complete *game);
int		megatroll(t_complete *game);
#endif
