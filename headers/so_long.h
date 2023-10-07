/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:08:37 by mcamilli          #+#    #+#             */
/*   Updated: 2023/10/06 11:15:19 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <time.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../printf/ft_printf.h"

typedef struct t_start
{
	int		cin;
	int		winh;
	int		winw;
	int		pd;
	int		ed;
	int		a;
	int		b;
	int		z;
	int		t;
	int		f;
	int		en;
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
	void	*enemyf1;
	void	*enemyf2;
	void	*barrier;
	void	*playerdown;
	void	*playerup;
	void	*playerleft;
	void	*playerright;
	void	*exit;
	void	*collectable;
}	t_complete;

void	takepositionenemy2(t_complete *game, int a, int b);
void	proportions(t_complete *game);
void	enemyframe(t_complete *game);
void	playerframe(t_complete *game);
void	printinfo(t_complete *game);
void	ifcenter2(t_complete *game);
int		foundp(t_complete *game, int a, int b);
int		proxymity(t_complete *game, int x);
int		printproxymity(t_complete *game, int x);
void	takepositionenemy(t_complete *game);
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
void	adding_in_graphics_aroundp(t_complete *game);
int		controls_working(int command, t_complete *game);
int		exit_point(t_complete *game);
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
void	ifcenter(t_complete *game);
int		pathfind(t_complete *game);
int		startgame(int ac, char **av, t_complete *game);
void	changeit(t_complete *game, int a, int b);
int		scan(t_complete *game);
int		controlpath(t_complete *game);
int		sq(t_complete *game, int x, int y, char a);
int		right(t_complete *game);
int		left(t_complete *game);
int		down(t_complete *game);
int		up(t_complete *game);
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
