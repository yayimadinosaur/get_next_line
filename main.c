#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd_test;
	char	*line;
	int		gnl_call;

	gnl_call = 1;
	if (ac == 2)		//handling only 1 fd
	{
		fd_test = open(av[1], O_RDONLY);
		while (get_next_line(fd_test, &line) != 0)
		{
			printf("getnextline call # = [%i]\n", gnl_call);
			printf("main line str = %s\n", line);
			gnl_call++;
		}
		printf("main - finished reading GNL == 0\n");
		close(fd_test);
	/*	while (line != 0)	//print store
		{
			printf("testing line str = %s\n", line);
			i++;
		}
		while (i > -1)			//free stores
		{
			free(store);
			i--;
		}
*/
		free(line);
	}
	else
		printf("not enough args\n");
	return (0);
}
