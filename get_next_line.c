




































#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				i;		//line index
	int				j;		//tmp index
	char			tmp[BUFF_SIZE];
	static char		buff[BUFF_SIZE];

	i = 0;
	j = 0;
	if (fd == -1)
		return (-1);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		if (!(line[i] = (char*)malloc(sizeof(char) * (BUFF_SIZE))))
			return (-1);
		while (tmp[j] != '\0' || buff[j] != '\n')
		{
			ft_strcpy(buff, line[i]);
		}
		i++;
	}
	return (fd);
}
