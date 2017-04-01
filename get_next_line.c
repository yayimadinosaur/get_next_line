
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				count;
	char			tmp[BUFF_SIZE + 1];
	static char		*buff;

	if (fd == -1 || !(buff = ft_memalloc(BUFF_SIZE)))
		return (-1);
	while (count = (read(fd, tmp, BUFF_SIZE) > 0))	//count bytes read
	{												//might be diff vs BUFF_SIZE
		tmp[count] = '\0';		//set last to null
		if (ft_strchr(const)tmp, 10 != NULL)
			break;
		if (ft_strcmp(tmp, buff) != 0)
			buff = ft_strdup(tmp);	//duplicate buff to tmp
		if (!buff)
			return (-1);
		ft_memalloc(tmp);		//clear tmp
	}
	&line = ft_strdup(tmp);
	free(tmp);
	return (1);
}
