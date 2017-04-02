
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				count;
	char			tmp[BUFF_SIZE + 1];
	static char		*buff;

	buff = NULL;
	if (fd == -1)
		return (-1);
	while (count = (read(fd, tmp, BUFF_SIZE) > 0))	//count bytes read
	{												//might be diff vs BUFF_SIZE
		tmp[count] = '\0';
		if (buff == NULL)
			buff = ft_strdup(tmp);
		else
			buff = ft_strjoin(buff, tmp);
		if (!buff)
			return (-1);
		if (ft_strchr(const)buff, 10 != NULL)
			break;
		ft_memalloc(tmp);		//clear tmp
	}
	ft_memccpy((void)&line, (const void)buff, 10, ft_strlen(buff));
	return (1);
}
