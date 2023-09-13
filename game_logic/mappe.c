
#include <stdio.h>
#include "../headers/so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int   main(int ac, char **av)
{
  int   fd1;
  char *line;
  //int x = 0;
  t_complete game;
    if (ac == 2)
  {
    fd1 = open(av[1], O_RDONLY);
    line = get_next_line(fd1);
   game.map = ft_split(line, '\n');
    ft_putstr(game.map[0]);
    //printf("%s", line);
    printf("sono arrivato qua2");
    free (line);
  }

  return (0);
}

