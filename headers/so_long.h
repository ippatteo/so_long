/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:08:37 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/22 13:55:41 by mcamilli         ###   ########.fr       */
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
# include "../minilibx/mlx.h"
# include "../printf/ft_printf.h"

typedef struct t_start
{
	int		p1y;
	int		p1x;
	int		steps;
	int		width;
	int		height;
	int		coins;
	char	**map;
}	t_complete;

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
