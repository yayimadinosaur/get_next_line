#include "get_next_line.h"

//warren main
//
int		main(int ac, char **av)
{
	int		fd_test;
	char	*line;
	int		gnl_call;

	gnl_call = 1;
	if (ac == 2)		//handling only 1 fd
	{
		fd_test = open(av[1], O_RDONLY);
	//	printf("START GNL BUFF SIZE = %i\n", BUFF_SIZE);
		while (get_next_line(fd_test, &line) > 0)
		{
		//	printf("getnextline call # = [%i]\n", gnl_call);
			if (gnl_call == 6)
				break;
		//	printf("-----------------------------main line str = [%s]\n", line);
		printf("main GNL call %i ret 1 [%s]", gnl_call, line);
		printf("\n");
			gnl_call++;
		}
		printf("----------------------ret 0 last str = [%s]\n", line);
		//printf("main - finished reading GNL == 0\n");
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
