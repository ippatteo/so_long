/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:22:08 by mcamilli          #+#    #+#             */
/*   Updated: 2023/09/13 19:47:08 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void ft_putstr(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	getmap(int	ac, char	**av)
{
	int			fd1;
	char		*line;
	t_complete	game;

	if (ac == 2)
	{
		fd1 = open(av[1], O_RDONLY);
		line = get_next_file(fd1);
		game.map = ft_split(line, '\n');
		free (line);
	}
  else
	  return (NULL);
  return (0);
}

