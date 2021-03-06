/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:54:54 by wfung             #+#    #+#             */
/*   Updated: 2017/04/13 19:11:04 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd_test;
	char	*line;
	int		gnl_call;
	int		ret;

	gnl_call = 1;
	if (ac == 2)
	{
		fd_test = open(av[1], O_RDONLY);
		while (gnl_call < 7)
		{
			ret = get_next_line(fd_test, &line);
			printf("main GNL call [%i] line = [%s] ret = [%i]\n", gnl_call, line, ret);
			gnl_call++;
			if (ret == 0)
				close(fd_test);
		}
	}
	else
		printf("not enough args\n");
	return (0);
}
