




































#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int		i;
	char	*buff;

	i = 0;
	if (fd == -1)
		return (-1);
	while (read(fd, line[i], BUFF_SIZE) > 0)
	{
		if (!(line[i] = (char*)malloc(char) * (BUFF_SIZE)))
			return (-1);
		
	}

	return (fd);
}
