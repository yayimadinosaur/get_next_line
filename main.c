#include <fcntl.h>		//to use OPEN for FD
#include <stdio.h>		//to use PRINTF

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd_test;
	int		i;
	char	*store;
	int		gnl_call;

	i = 0;
	gnl_call = 1;
	if (ac == 2)		//handling only 1 fd
	{
		fd_test = open(av[1], O_RDONLY);
		while (get_next_line(fd_test, &store) == 1)
		{
			printf("getnextline call # = [%i]\n", gnl_call);
			gnl_call++;
		}	
		close(fd_test);
		i = 0;		//reset i
		while (store != 0)	//print store
		{
			printf("testing line str = %s\n", store);
			i++;
		}
		while (i > -1)			//free stores
		{
			free(store);
			i--;
		}
	}
	else
		printf("not enough args\n");
	return (0);
}
