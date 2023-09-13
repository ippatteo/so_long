
#include "get_next_line.h"

int   main(int ac, char **av)
{
  char  *line;
  int   fd1;
  int   fd2;

  fd1 = open(av[1], O_RDONLY);
  fd2 = open(av[2], O_RDONLY);
  printf("%s", get_next_line(fd1));
  printf("%s", get_next_line(fd1));
  return (0);
}
