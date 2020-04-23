#include "get_next_line.h"

/*int   main(int ac, char **av)
{
  char  *line;
  int   fd1;
  int   fd2;

  fd1 = open(av[1], O_RDONLY);
  fd2 = open(av[2], O_RDONLY);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  return (0);
}*/

int main(void)
{   
    int			fd;
	int			ret;
	char		*line;

	fd = open("./test1.txt", O_RDONLY);
	printf("Começou\n");
	while((ret = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
	}
    printf("Terminou\n");
	return (0);
}