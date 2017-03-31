
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				count;
	char			*pos;
	char			*tmp;
	static char		buff[BUFF_SIZE + 1];

	if (fd == -1)
		return (-1);
	while ((count = (read(fd, buff, BUFF_SIZE)) > 0))	//count bytes read
	{												//might be diff vs BUFF_SIZE
		buff[count] = '\0';		//set last to null
		tmp = ft_strdup(buff);	//duplicate buff to tmp
		if ((pos = ft_strchr((const)tmp, 10)))	//& is returned if true
			break;
		else
			ft_strjoin(, tmp);
		free(tmp);
	}
	&line = ft_strdup(buff);
	free(tmp);
	return (1);
}
