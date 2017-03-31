#include <fcntl.h>		//to use OPEN for FD
#include <stdio.h>		//to use PRINTF

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd_test;
	int		i;
	char	**store;

	i = 0;

	store[BUFF_SIZE] = NULL;
	if (ac == 2)		//handling only 1 fd
	{
		fd_test = open(av[1], O_RDONLY);
		while (get_next_line(fd_test, store) > 0)
		{
			while (store[i] != 0)
			{
				printf("%s\n", store[i]);
				i++;
			}
			close(fd_test);
		}
		else
			printf("failed GNL\n");
	}
	else
		printf("not enough args\n");
	return (0);
}
